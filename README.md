# Lil Genius

**Lil Genius** is an interactive educational web project designed for young learners. It features multiple fun and engaging pages covering various topics with multimedia content such as images, audio, and videos to create an immersive learning experience.
---
**Website** - https://lilgenius.netlify.app/
---

## Features

- Educational pages covering topics like animals, age, and more.
- Multimedia integration with images, audio narrations, and videos.
- Simple, kid-friendly navigation and interface.
- Responsive design works on modern browsers across devices.
- Modular folder structure for easy content updates.

---

## Project Structure

lil-genius/
├── audio/ # Audio files for narration or sounds
├── img/ # Images used in educational content
├── video/ # Video files embedded in pages
├── index.cpp # C++ source file (for backend/native logic)
├── *.html # HTML files for different topic pages (e.g. animal.html, age.html)
├── style.css # CSS stylesheet
└── script.js # JavaScript for interactivity (if any)

yaml
Copy
Edit

---

## Getting Started

### Prerequisites

- A modern web browser (Chrome, Firefox, Edge, Safari)
- Optional: Local server for better resource handling (e.g., Live Server in VSCode)

### How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/dhruv-dhemare/lil-genius.git
   cd lil-genius
Open any .html file in your browser to explore the content.

For best results, run a local web server in the project directory:

bash
Copy
Edit
# Python 3
python3 -m http.server 8000
Then open http://localhost:8000 in your browser.

About the C++ File (index.cpp)
The project includes a C++ source file (index.cpp), which may be used for backend processing or native logic integration. To compile and run it, use a C++ compiler like g++:

bash
Copy
Edit
g++ index.cpp -o index
./index
(Add specific instructions here if you use it in a particular way.)

Contributing
Contributions are welcome! Please:

Fork the repo

Create a feature branch (git checkout -b feature-name)

Commit your changes (git commit -m "Add feature")

Push to your branch (git push origin feature-name)

Create a Pull Request

License
This project is licensed under the MIT License.

Contact
Dhruv Dhemare
GitHub: https://github.com/dhruv-dhemare
Email: (dhruvdhemare@gmail,com)
