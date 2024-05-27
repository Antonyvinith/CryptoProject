import React, { useEffect, useState } from "react";
import axios from "axios";
import Sidebar from "../components/Sidebar";
import Navebar from "../components/Navebar";
import { Box } from "@mui/material";
import { Button } from "react-bootstrap";
import "../Styling/SidebarStyle.css";
import ReactAudioPlayer from "react-audio-player";

function CategoryList() {
  const [audioFiles, setAudioFiles] = useState([]);

  useEffect(() => {
    const importAudios = async () => {
      try {
        const context = require.context(
          "../PythonDecrypt/Audio",
          false,
          /\.(mp3|wav|ogg)$/
        );
        const keys = context.keys();
        const audioPaths = await Promise.all(
          keys.map(async (key) => {
            const audio = await import(
              `../PythonDecrypt/Audio/${key.slice(2)}`
            );
            return audio.default;
          })
        );
        setAudioFiles(audioPaths);
      } catch (err) {
        console.error("Error importing audios:", err);
      }
    };
    importAudios();
  }, []);

  return (
    <>
      <Navebar />
      <Box height={40} />
      <Box sx={{ display: "flex" }} className="pageBack">
        <Sidebar />
        <Box component="main" sx={{ flexGrow: 1, p: 3 }}>
          <div className="container">
            <div className="py-">
              <Box height={40} />
              <h1>Audio Data</h1>
              {audioFiles.map((audioFile, index) => (
                <div key={index} style={{ marginBottom: "20px" }}>
                  <ReactAudioPlayer
                    src={audioFile}
                    controls
                    listenInterval={1000}
                    volume={0.5}
                    loop
                    playbackRate={1.2}
                    style={{
                      backgroundColor: "lightgray",
                      borderRadius: "5px",
                    }}
                  />
                </div>
              ))}
            </div>
          </div>
        </Box>
      </Box>
    </>
  );
}

export default CategoryList;
