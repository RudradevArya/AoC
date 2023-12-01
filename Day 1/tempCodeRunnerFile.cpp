// Check if the file is open
    if (!inp.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;  // Return an error code
    }