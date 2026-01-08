# 🔐 SecureVault - Password Manager

A secure, personal password manager with both a **web interface** and **command-line (C++)** version. Store, encrypt, and manage your credentials safely.

---

## ✨ Features

- **Master Password Protection** – Unlock your vault with a single master key
- **XOR Encryption** – All passwords are encrypted before storage
- **Add / View / Search / Delete** credentials
- **Modern Glassmorphism UI** with smooth animations
- **Local Storage** – No external servers, data stays on your device

---

## 🌐 Web Version

### Files

| File         | Description                            |
| ------------ | -------------------------------------- |
| `index.html` | Main HTML structure                    |
| `style.css`  | Glassmorphism styling with animations  |
| `script.js`  | Encryption logic & password management |

### Usage

1. Open `index.html` in any modern browser
2. Enter your **Master Password** to unlock
3. Add credentials (website, username, password)
4. Search and manage your saved passwords

> **Note:** Web version uses browser's `localStorage` for persistence.

---

## 💻 C++ Command-Line Version

### Files

| File                              | Description                          |
| --------------------------------- | ------------------------------------ |
| `main.cpp`                        | Main application with menu interface |
| `encryption.cpp` / `encryption.h` | Password encryption/decryption       |
| `database.cpp` / `database.h`     | File-based storage operations        |
| `Record.h`                        | Data structure for credentials       |
| `data/`                           | Directory for stored records         |

### Build & Run

```bash
# Compile
g++ main.cpp encryption.cpp database.cpp -o main

# Run
./main
```

### Menu Options

1. **Add Password** – Save new credentials
2. **View Passwords** – List all stored passwords
3. **Search Password** – Find by website
4. **Delete Password** – Remove a record
5. **Exit** – Close the application

---

## 🔒 Security Notes

- Uses XOR cipher with master key for encryption
- Passwords are never stored in plain text
- For production use, consider upgrading to AES or other robust encryption

---

## 📁 Project Structure

```
password manager/
├── index.html          # Web UI
├── style.css           # Styling
├── script.js           # Web app logic
├── main.cpp            # C++ entry point
├── encryption.cpp      # Encryption functions
├── encryption.h
├── database.cpp        # Data persistence
├── database.h
├── Record.h            # Record struct
├── data/               # Stored records (C++)
└── README.md
```

---

## 📜 License

This project is for personal/educational use.

