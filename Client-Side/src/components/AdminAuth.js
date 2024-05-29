import React from "react";
import { useState } from "react";
import { NavLink } from "react-router-dom";
import axios from "axios";
import { useNavigate } from "react-router-dom";
import "../Styling/Admin.css";
import { Button, Card } from "react-bootstrap";
import Input from "../customComponents/Input";

function AdminAuth() {
  const navigate = useNavigate();
  const [tab, setTab] = useState(true);
  const [firstName, setFirstName] = useState("");
  // const [name, setName] = useState("");
  const [lastName, setLastName] = useState("");
  const [dob, setDob] = useState("");
  const [phone, setPhone] = useState("");
  const [username, setUsername] = useState("");
  const [email, setEmail] = useState("");
  const [token, setToken] = useState("");
  const [password, setPassword] = useState("");
  const [image, setImage] = useState(
    "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAALEAAACUCAMAAADrljhyAAAAMFBMVEXk5ueutLenrrHf4uPn6eqrsbTq7O3b3t/Jzc+4vcC1ur3Gysyxt7rX2tu9wcTR1dbDLeoMAAAEQUlEQVR4nO2c23LjIAxAMQhsDIb//9sFN93EmTQBhCW66/PQzqR9OKMR4qoIcXFxcXFxcXFxcXFxcXHxLwIZbokidk21xSURo/r+ZFhAzNFZLaXUifRrsi7OYlhno5bgtZ4OaO1DFIbb7RVGOD896d6kJ+8GzA3l5Evdm7R0aihnEIt/45uRaxwoziDsB989zuOEGbZPAb4p+3kQ5aXINyvLyO2aAVcqnJ0X/ihXCQ+hXCecagazMhTn8F05cirDVi2cYKwYIHyDsLaMdblk4nihHLh8G5L4psyVyqrNN8NjbEJjiPMSg2XBrGR7jKeZQRgsQlg7BuEZITxNnj7IleuJZ+RCbqxWVIy1JzeOqBCnIFOnBTIpOAocUjgpExvPmGK8Q5wW6KQg340YXKXYCaRpYdBJMU2WUlgodFJQT3sRLzz5jTCRYelgPFGu68H9NmMTOgiTlrf/1dj9OuPfF2NS4x61gtS4+WzlAGk9xu5AyI1F05nmE8S3Ih3WbquiFDYdYmxpV/SYA6EbtCv6HsWC+EgWdUy4I0nTONFyn3DAU59XoE9YqG/J2m6ZHiBPitZbm78hDuQXC8itnma4U1eYsactfVIgD7JYbqcBUZJXBt+cyc3KbLfpa+udKfnscQO2xhBrhmF3U24cfJyvhZrygu3qPwFNSzhG4UT9zanmFW44Sd64jSHWJQblMfdPbBXKcoh3kDCXVgxNu+H/GVChKMw6DCK8Pz9+foz+wleyj7lHQH3cknDOG68AE+3rV/R7fKewjff4H0QM06u39FpOLo7ZYQFCxVXKJ125RjWm7w4Y2Fy+Zfd+3wauboPx0uEZY0DNW2JWYMbXzX1M5s7Y7VhmD26MzoUQrLXpZ3BL3Ob8F265AymMSqkt9zRJuTdhPQy8r4/2hiylhugjgxxWF1KJeDuDZPMpuLgpXmkwKjq76s9T9Le3t2GZ2aTTlJGnucqdXvp37xjWnHmyCO8T4Z21XJeZ9DE9iM35Zt+dlNWRzBkg2rLWq/eBThOioqh6RWvhYutw+pIjtw52uC69K2t38huyaHv67s7+xEZDM9t+CfGAX8wpziDK9p8NSH/CFjAViNbT4gL01D01UoBPSYi789r3sKj8EKVdueslKnQswT8ju3XBgXBnDbkjeu2zQgLV3nFVq+x7nGqA6rCGKHeOaGVa4Q43fQRF4glsf6SiFkYnBr1wSgzEXAJkVeJIc5Hr0FjTRuvlA/RooWiisaEa2ZaJou3rDAzu6RIO3bDE6PPEuNm44RkqouG8C9V5wVXY/rJW7rE5h90Xtd0ibKX4QbkuxvjHunjjqmZfxNcm9ENWpQV/iOve+/ZpUEFTU5M7dOr2oHjZCTP6yXkXytOCb9F2pOIFCX8x/qK4P1l1aE/pQvH+iX2G/qb0i0Sg5jnYqRR/vwzryvjAWpgVowy88tVQkMNQaKzG4YXdH8y5Ow3nGSvFAAAAAElFTkSuQmCC"
  );
  const [customerID, setCustomerID] = useState();

  const [firstNameErr, setFirstNameErr] = useState("");
  const [emailErr, setEmailErr] = useState("");
  const [lastNameErr, setLastNameErr] = useState("");
  const [dobErr, setDobErr] = useState("");
  const [phoneErr, setPhoneErr] = useState("");
  const [usernameErr, setUsernameErr] = useState("");
  const [passErr, setPassErr] = useState("");

  function login() {
    if (username.length < 3 || password.length < 3) {
      alert("Enter valid details");
    }
    if (
      // (username == "Antony"||"Vinith"||"adbhi"|| "swarup"&& password == "123"||"Admin"||"adbhi"||"swarup")
      (username == "Vinith" && password == "123") ||
      (username == "admin" && password == "admin") ||
      (username == "adbhi" && password == "adbhi") ||
      (username == "swarup" && password == "swarup")
    ) {
      navigate("/dashboard");
      alert("Login successfull");
    } else {
      alert("Invalid Credentials");
    }
    //   else {
    //   const url = "http://localhost:3000/login";
    //   axios
    //     .get(url, { username, password })
    //     .then((res) => {
    //       console.log(res.data);
    //       if (res.data) {
    //         navigate("/dashboard");
    //         alert("Login successfull");
    //       } else {
    //         alert(res.data.message);
    //       }
    //     })
    //     .catch((err) => {
    //       alert("Invalid login Credentials: ");
    //     });
    // }
  }
  function createAccountAdmin() {
    console.log(firstName, lastName, dob, phone, email, password, image);

    console.log(firstName);
    console.log(lastName);
    {
      const url = "http://localhost:3000/CreateAdmin";
      axios
        .post(url, {
          firstName: firstName,
          lastName: lastName,
          dateOfBirth: dob,
          phone: phone,
          email: email,
          userInput: {
            username: username,
            password: password,
            type: "ADMIN",
          },
        })
        .then((res) => {
          if (res.data) {
            console.log(res.data);
            setFirstName(res.data.firstName);
            setLastName(res.data.lastName);
            setDob(res.data.dateOfBirth);
            setEmail(res.data.email);
            setPhone(res.data.phone);

            localStorage.setItem(
              "username",
              res.data.responseData.user.username
            );

            /*
                navigate to the actual dashboard
            */
            navigate("/dashboard");
          } else {
            alert(res.data.message);
          }
        })
        .catch((err) => {
          console.log("error: ", err);
        });
    }
  }

  function handleForgotClick() {
    console.log("forgot clicked");
    localStorage.clear();
    navigate("/forgotAdmin");
  }

  return (
    <>
      {tab ? (
        <>
          <div className="wrapper" style={{ marginTop: "50px" }}>
            <div className="backgroundadmin" id="admin"></div>
            <div className="login-container">
              <div className="login">
                <center>
                  <b className="blogin">Admin Login</b> <br />
                  <br />
                  <br />
                  <center>
                    <Input
                      text={"Username"}
                      placeholder={"Enter your username"}
                      value={username}
                      func={setUsername}
                      Id={"username"}
                      Error={setUsernameErr}
                      Errormsg={usernameErr}
                    />
                    <Input
                      text={"Password"}
                      placeholder={"Enter your password"}
                      value={password}
                      func={setPassword}
                      type={"password"}
                      Id={"password"}
                      Error={setPassErr}
                      Errormsg={passErr}
                    />
                  </center>
                  <center></center>
                  <Button size="sg" variant="secondary" onClick={login}>
                    Login
                  </Button>
                </center>
                <br />
              </div>
            </div>
          </div>
          <br />
        </>
      ) : (
        <>
          <div className="wrapper1">
            <div className="backgrounda"></div>
            <div className="signup-container">
              <div className="signup">
                <center>
                  <b className="blogin">Admin Sign Up</b>
                  <br />
                  <br />
                  <Card></Card>
                  <Input
                    text={"First Name"}
                    placeholder={"Enter your first name"}
                    value={firstName}
                    func={setFirstName}
                    Id={"firstName"}
                    Error={setFirstNameErr}
                    Errormsg={firstNameErr}
                  />
                  <Input
                    text={"Last Name"}
                    placeholder={"Enter your last name"}
                    value={lastName}
                    func={setLastName}
                    Id={"lastName"}
                    Error={setLastNameErr}
                    Errormsg={lastNameErr}
                  />
                  <Input
                    text={"Date of birth"}
                    placeholder={"YYYY-MM-DD"}
                    value={dob}
                    func={setDob}
                    type={"date"}
                    Id={"dob"}
                    Error={setDobErr}
                    Errormsg={dobErr}
                  />
                  <Input
                    text={"Mobile"}
                    placeholder={"Enter your mobile number"}
                    value={phone}
                    func={setPhone}
                    type={"tel"}
                    Id={"phone"}
                    Error={setPhoneErr}
                    Errormsg={phoneErr}
                  />
                  <Input
                    text={"Email"}
                    placeholder={"Enter your email"}
                    value={email}
                    func={setEmail}
                    // type={"email"}
                    Id={"email"}
                    Error={setEmailErr}
                    Errormsg={emailErr}
                  />
                  <Input
                    text={"Username"}
                    placeholder={"Enter your username"}
                    value={username}
                    func={setUsername}
                    Id={"username"}
                    Error={setUsernameErr}
                    Errormsg={usernameErr}
                  />
                  <Input
                    text={"Password"}
                    placeholder={"Enter your password"}
                    value={password}
                    func={setPassword}
                    type={"password"}
                    Id={"password"}
                    Error={setPassErr}
                    Errormsg={passErr}
                  />
                  <br />
                  <Button
                    size="sg"
                    variant="secondary"
                    onClick={createAccountAdmin}
                  >
                    Create Admin account
                  </Button>
                  <br></br>
                  <br />
                </center>
                <center>
                  Already have an account?{" "}
                  <NavLink onClick={() => setTab(true)}>
                    <u>Sign In</u>
                  </NavLink>{" "}
                </center>
              </div>
            </div>
          </div>
        </>
      )}
    </>
  );
}
export default AdminAuth;
