//  DOM ELEMENTS 
const masterKeyInput = document.getElementById("masterKey");
const masterSection = document.getElementById("master-section");
const app = document.getElementById("app");

const websiteInput = document.getElementById("website");
const usernameInput = document.getElementById("username");
const passwordInput = document.getElementById("password");
const searchInput = document.getElementById("search");
const passwordList = document.getElementById("passwordList");

let masterKey = "";

//  ENCRYPTION 
function encrypt(text, key) {
    let res = "";
    for (let i = 0; i < text.length; i++) {
        res += String.fromCharCode(
            text.charCodeAt(i) ^ key.charCodeAt(i % key.length)
        );
    }
    return btoa(res);
}

function decrypt(text, key) {
    let decoded = atob(text);
    let res = "";
    for (let i = 0; i < decoded.length; i++) {
        res += String.fromCharCode(
            decoded.charCodeAt(i) ^ key.charCodeAt(i % key.length)
        );
    }
    return res;
}

// MASTER LOGIN 
function setMasterKey() {
    masterKey = masterKeyInput.value;

    if (!masterKey) {
        alert("Please enter a master password");
        return;
    }

    masterSection.style.display = "none";
    app.classList.remove("hidden");

    loadPasswords();
}

// ADD PASSWORD 
function addPassword() {
    const website = websiteInput.value;
    const username = usernameInput.value;
    const password = passwordInput.value;

    if (!website || !username || !password) {
        alert("Fill all fields");
        return;
    }

    let data = JSON.parse(localStorage.getItem("vault")) || [];

    data.push({
        website,
        username,
        password: encrypt(password, masterKey)
    });

    localStorage.setItem("vault", JSON.stringify(data));

    websiteInput.value = "";
    usernameInput.value = "";
    passwordInput.value = "";

    loadPasswords();
}

//  LOAD PASSWORDS 
function loadPasswords() {
    passwordList.innerHTML = "";

    let data = JSON.parse(localStorage.getItem("vault")) || [];

    data.forEach((item, index) => {
        const li = document.createElement("li");

        li.innerHTML = `
            <b>${item.website}</b><br>
            ${item.username}<br>
            Password: ${decrypt(item.password, masterKey)}
            <span class="delete" onclick="deletePassword(${index})">✖</span>
        `;

        passwordList.appendChild(li);
    });
}

// DELETE 
function deletePassword(index) {
    let data = JSON.parse(localStorage.getItem("vault"));
    data.splice(index, 1);
    localStorage.setItem("vault", JSON.stringify(data));
    loadPasswords();
}

//  SEARCH 
function searchPassword() {
    const query = searchInput.value.toLowerCase();
    const items = passwordList.getElementsByTagName("li");

    for (let item of items) {
        item.style.display = item.innerText.toLowerCase().includes(query)
            ? "block"
            : "none";
    }
}
