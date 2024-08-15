# Castway

## Overview

Welcome to **Castaway**! Castaway is a multiplayer sandbox survival ASCII game set on remote island where main character
have to survive in harsh conditions.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Installation

### Prerequisites

Before running the game, ensure you have the following installed:

- [GNU Compiler Collection](https://gcc.gnu.org/) - Version 11.4 or above
- [ncurses](https://invisible-island.net/ncurses/) - Version 6.3 or above
- [valgrind](https://valgrind.org/) - Version 3.23 or above
- [criterion](https://criterion.readthedocs.io/en/master/intro.html) - Version 2.4 or above

### Setup

1. Clone the repository:

    ```bash
    git clone https://github.com/without-eyes/Castaway.git
    ```

2. Navigate to the project directory:

    ```bash
    cd Castaway
    ```

3. Install libraries:

    ```bash
    sudo apt-get install libncurses5-dev libncursesw5-dev
    sudo apt-get install valgrind
    apt-get install libcriterion-dev
    ```

4. Run the game:

    ```bash
    make
    ```

## Usage

### Controls

- **Move and attack**: WASD

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch:

    ```bash
    git checkout -b feature/your-feature-name
    ```

3. Make your changes and commit them:

    ```bash
    git commit -m "Add your message here"
    ```

4. Push to your branch:

    ```bash
    git push origin feature/your-feature-name
    ```

5. Open a Pull Request.

## License

This project is licensed under the [MIT License](LICENSE).
