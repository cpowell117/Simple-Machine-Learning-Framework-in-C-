This project is a minimalistic Machine Learning (ML) framework developed in C++, focusing on linear regression. It includes basic data handling through a custom DataFrame class and implements linear regression modeling with gradient descent optimization. This framework is designed as a learning tool to understand the fundamentals of ML algorithms and data manipulation in C++.

The project structure comprises:
- 'DataFrame.h': A header file defining the DataFrame class for loading and manipulating datasets from CSV files.
- 'LinearRegression.h': A header file defining the LinearRegression class, which implements the fitting (training) and prediction logic for linear regression.
- 'main.cpp': The main program demonstrating the usage of DataFrame and LinearRegression with a simple dataset.
  
-----------------------------------------------------------------------------
Steps to Run the Project
To successfully run this project on another computer, follow these steps:

1. Clone the Repository

- First, clone this repository to your local machine using Git:
  git clone <repository-url>
- Replace <repository-url> with the actual URL of this GitHub repository.
  
2. Prepare the Dataset
   
- Ensure you have two CSV files, train.csv and test.csv, containing the training and testing datasets, respectively. Each CSV file should have two columns: one for the independent variable (feature) and one for the dependent variable (target).
- Place these CSV files in a known directory on your computer.
  
3. Update File Paths

- In 'main.cpp', update the file paths in the read_csv calls to point to the locations of your train.csv and test.csv files:
  df.read_csv("/path/to/train.csv");
  testDf.read_csv("/path/to/test.csv");
- Replace '/path/to/train.csv' and '/path/to/test.csv' with the actual paths to your dataset files.
  
4. Compile the Project

- Open a terminal or command prompt.
- Navigate to the project directory where you cloned the repository.
- Compile the project using 'g++' with C++11 support enabled:
g++ -std=c++11 main.cpp -o ml_framework
- This command compiles main.cpp and outputs an executable named 'ml_framework'.
  
5. Run the Executable

- In the same terminal or command prompt, run the compiled executable:
  ./ml_framework
- The program will load the datasets, train the linear regression model using the training data, and then make predictions on the test dataset.
  
Dependencies
- A C++ compiler with C++11 support (e.g., GCC, Clang)
- No external libraries are required.
