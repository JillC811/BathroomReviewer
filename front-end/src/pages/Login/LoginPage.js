import React from 'react'

import { useNavigate } from 'react-router-dom'

import styles from "./login-page.module.css"

export default function LoginPage() {

    const navigate = useNavigate()
    const [loginMode, setLoginMode] = React.useState("login") // login or register

    const signIn = async (e) => {
        const email = e.target[0].value
        const password = e.target[1].value

        // TODO: re

        const signInUser = await fetch(
            "http://localhost:8000/users/login",
            {
                method: "post",
                headers: {
                "Content-type": "application/json",
                },
                body: JSON.stringify({
                email,
                password
                }),
            }
        );

        navigate("/home")
        console.log("signed in")
    }

    const register = async (e) => {
        const first_name = e.target[0].value
        const last_name = e.target[1].value
        const email = e.target[2].value
        const password = e.target[3].value

        console.log(first_name, last_name, email, password)

        // const createUser = await fetch(
        //     "http://localhost:8000/users",
        //     {
        //         method: "post",
        //         headers: {
        //         "Content-type": "application/json",
        //         },
        //         body: JSON.stringify({
        //         first_name,
        //         last_name,
        //         email,
        //         password
        //         }),
        //     }
        // );
        // const createUserResponse = await createUser.json();


        // TODO: set state of user's credentials and that they're signed in

        // Route to home
        navigate("/home")

        console.log("registered")
    }

    const handleSubmit = (e) => {
        if (loginMode === "login") {
            signIn(e)
        } else {
            register(e)
        }
    }

    const changeLoginMode = () => {
        if (loginMode === "login") {
            setLoginMode("register")
        } else {
            setLoginMode("login")
        }
    }

    return (
        <div className={styles.loginContainer}>
            <h1>Flushable</h1>
            <h4>Western's Bathroom Rating App</h4>
            
            <br />
            <br />
            <br />
            <h2>{loginMode === "login" ? "Sign-In" : "Create an Account"}</h2>
            <form onSubmit={handleSubmit}>
                {
                    loginMode === "register" &&
                    <>
                        <p>
                            <label>First Name</label>
                            <br/>
                            <input type="text" name="first_name" required />
                        </p>
                        <p>
                            <label>Last Name</label>
                            <br/>
                            <input type="text" name="last_name" required />
                        </p>
                    </>
                }
                <p>
                    <label>Email address</label><br/>
                    <input type="email" name="email" required />
                </p>
                <p>
                    <label>Password</label>
                    <br/>
                    <input type="password" name="password" required />
                </p>
                <br />
                <p>
                    <button id="sub_btn" type="submit">{loginMode === "login" ? "Sign-In" : "Create an Account"}</button>
                </p>
            </form>
            <footer>
                <button className={styles.loginOrRegisterButton} onClick={changeLoginMode}>{loginMode === "login" ? "Create an Account" : "Sign-In"}</button>
            </footer>
        </div>
    )
}
