<!doctype html>
<html lang="en">
<head>
    <title>
        HMS-login
    </title>
    <link rel="stylesheet" href="http://localhost/HM_system/login.css">
</head>
<body>
    <h1 id="title">HYDROPONIC MONITORING SYSTEM</h1>
    <div class="hero">
        
        <div class="form-box">
            <div class="button-box">
                <div id="btn"></div>
                <button type="button" class="toggle-btn" onclick="login()">Log in</button>
                <button type="button" class="toggle-btn" onclick="register()">Register</button>

            </div>
      
            <form id="login" class="input-group" action="validation.php" method="post">
            <input type="text" class="input-field" name="user" placeholder="User Id" required>
            <input type="password" name="password" class="input-field" placeholder="Enter Password"
            required>
            <input type="checkbox" class="chech-box"><span>Remember Password</span>
            <button type="submit" class="submit-btn">Log in</button>
            </form>
            <form id="register" class="input-group" action="registration.php" method="post">
            <input type="text" class="input-field" name="user" placeholder="User Id" required>
            <input type="password" name="password" class="input-field" placeholder="Enter Password"
            required>
            <input type="checkbox" class="chech-box"><span>I agree to the terms &
            conditions</span>
            <button type="submit" class="submit-btn">Register</button>
            </form>
        </div>
    </div>
    <script>
        var x = document.getElementById("login");
        var y = document.getElementById("register");
        var z = document.getElementById("btn");
        function register()
        {
        x.style.left = "-400px";
        y.style.left = "50px";
        z.style.left = "110px";
        }
        function login()
        {
        x.style.left = "50px";
        y.style.left = "450px";
        z.style.left = "0px";
        }   
    </script>

</body>
</html>