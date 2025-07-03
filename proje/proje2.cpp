/** 
* @file proje2.cpp 
* @description karmaşık sayılarla aritmetik işlemler
* @assignment 2.proje
* @date 02.01.2024
* @author
*/
#include <iostream>
#include <vector>
//abstract sınıf
class LinearAlgebraObject{  
    public:
        virtual void print()=0;
        virtual void operator+()const=0;
        virtual void operator-()const=0;
        virtual void operator*()const=0;
};

class Imaginary {
private:
    double im;

public:
    Imaginary(double imag) : im(imag) {}

    double getImaginary() const {
        return im;
    }
    void setIm(double im){
        this->im=im;
    }
    
};

class Complex : public Imaginary {
private:
    double re;

public:
    Complex(double real, double imag) : Imaginary(imag), re(real) {}

    double getReal() const {
        return re;
    }

    // Aritmetik işlemler
    Complex operator+(const Complex& other) const {
        return Complex(re + other.getReal(), getImaginary() + other.getImaginary());
    }

    Complex operator-(const Complex& other) const {
        return Complex(re - other.getReal(), getImaginary() - other.getImaginary());
    }

    Complex operator*(const Complex& other) const {
        double realPart = re * other.getReal() - getImaginary() * other.getImaginary();
        double imagPart = re * other.getImaginary() + getImaginary() * other.getReal();
        return Complex(realPart, imagPart);
    }

    Complex operator/(const Complex& other) const {
        // Bölme işlemi 
        double denominator = other.getReal() * other.getReal() + other.getImaginary() * other.getImaginary();
        double realPart = (re * other.getReal() + getImaginary() * other.getImaginary()) / denominator;
        double imagPart = (getImaginary() * other.getReal() - re * other.getImaginary()) / denominator;
        return Complex(realPart, imagPart);
    }

    //esitlik kontrolu
    bool operator==(const Complex& other) const {
        return (re == other.getReal()) && (getImaginary() == other.getImaginary());
    }
    //eslenik 
    Complex operator~() const
    {
        return Complex(re, -getImaginary());
    }

    // Toplama atama (+=) operatörü aşırı yükleme
    Complex &operator+=(const Complex &other)
    {
        re += other.re;
        setIm(getImaginary() + other.getImaginary());
        return *this;
    }

    // Çıkarma atama (-=) operatörü aşırı yükleme
    Complex &operator-=(const Complex &other)
    {
        re -= other.re;
        setIm(getImaginary() - other.getImaginary());
        return *this;
    }

    // Çarpma atama (*=) operatörü aşırı yükleme
    Complex &operator*=(const Complex &other)
    {
        double resultRe = re * other.re - getImaginary() * other.getImaginary();
        double resultIm = re * other.getImaginary() + getImaginary() * other.re;
        re = resultRe;
        setIm(resultIm);
        return *this;
    }
    // Bolme atama (/=) operatörü aşırı yükleme
    Complex &operator/=(const Complex &other) {
    double denominator = other.getReal() * other.getReal() + other.getImaginary() * other.getImaginary();
    double realPart = (re * other.getReal() + getImaginary() * other.getImaginary()) / denominator;
    double imagPart = (getImaginary() * other.getReal() - re * other.getImaginary()) / denominator;
    
    re = realPart;
    setIm(imagPart);
    
    return *this;
}
//complex sayi yazdirma
    void print()const{
        std::cout<<re<<" "<<"+"<<getImaginary()<<"i"<<std::endl;

    }
};

class Vector {
private:
    size_t size;
    std::vector<Complex> elements;

public:
    Vector(size_t s, const std::vector<Complex>& elems) : size(s), elements(elems) {}

    size_t getSize() const {
        return size;
    }

    const std::vector<Complex>& getElements() const {
        return elements;
    }

    Vector operator+(const Vector& other) const {
        if (size != other.getSize()) {
            std::cout<<"Vector sizes must be the same for addition.";
        }

        std::vector<Complex> resultElements;
        for (size_t i = 0; i < size; ++i) {
            resultElements.push_back(elements[i] + other.getElements()[i]);
        }

        return Vector(size, resultElements);
    }

    Vector operator-(const Vector& other) const {
        if (size != other.getSize()) {
            std::cout<<"Vector sizes must be the same for subtraction.";
        }

        std::vector<Complex> resultElements;
        for (size_t i = 0; i < size; ++i) {
            resultElements.push_back(elements[i] - other.getElements()[i]);
        }

        return Vector(size, resultElements);
    }

    Complex operator*(const Vector& other) const {
        if (size != other.getSize()) {
            std::cout<<"Vector sizes must be the same for dot product.";
        }

        Complex result(0, 0);
             for (size_t i = 0; i < size; ++i) {
            result = result + (elements[i] * other.getElements()[i]);
        }

        return result;
    }

  //atama
    Vector operator=(const Vector& other) {
    
    if (this != &other) {
        
        elements.clear();
        size = other.getSize();
        elements = other.getElements();
    }
    
    return *this;
}


    
    // Toplama atama (+=) operatörü aşırı yükleme
    Vector &operator+=(const Vector &other) {
    if (getSize() != other.getSize()) {
        std::cout << "Vector sizes must be the same for addition.";
        return *this;
    }

    for (size_t i = 0; i < getSize(); ++i) {
        elements[i] += other.getElements()[i];
    }

    return *this;
}

// Cıkarma atama (-=) operatörü aşırı yükleme 
Vector &operator-=(const Vector &other) {
    if (getSize() != other.getSize()) {
        std::cout << "Vector sizes must be the same for subtraction.";
        return *this;
    }

    for (size_t i = 0; i < getSize(); ++i) {
        elements[i] -= other.getElements()[i];
    }

    return *this;
}

// Carpma atama (*=)operatörü aşırı yükleme
Vector &operator*=(const Vector &other) {
    if (getSize() != other.getSize()) {
        std::cout << "Vector sizes must be the same for element-wise multiplication.";
        return *this;
    }

    for (size_t i = 0; i < getSize(); ++i) {
        elements[i] = elements[i] * other.getElements()[i];
    }

    return *this;
}

// Bolme atama (/=) operatörü aşırı yükleme
Vector &operator/=(const Vector &other) {
    if (getSize() != other.getSize()) {
        std::cout << "Vector sizes must be the same for element-wise division.";
        return *this;
    }

    for (size_t i = 0; i < getSize(); ++i) {
        // Check for division by zero
        if (other.getElements()[i] == Complex(0, 0)) {
            std::cout << "Division by zero is not allowed.";
            return *this;
        }

        elements[i] = elements[i] / other.getElements()[i];
    }

    return *this;
}

    //esit mi
    bool operator==(const Vector& other) const {
        return (size == other.getSize()) && (elements == other.getElements());
    }

    void print() const {
    for (const auto& element : elements) {
        std::cout << element.getReal() << " + " << element.getImaginary() << "i  ";
    }
    std::cout << std::endl;
}
   
};

class Matrix {
private:
    size_t row;
    size_t col;
    std::vector<std::vector<Complex>> elements;

public:
    Matrix(size_t r, size_t c, const std::vector<std::vector<Complex>>& elems)
        : row(r), col(c), elements(elems) {}

    size_t getRow() const {
        return row;
    }

    size_t getCol() const {
        return col;
    }

    const std::vector<std::vector<Complex>>& getElements() const {
        return elements;
    }

    Matrix operator+(const Matrix& other) const {
        if (row != other.getRow() || col != other.getCol()) {
            std::cout<<"Matrix dimensions must be the same for addition.";
        
        }

        std::vector<std::vector<Complex>> resultElements;
        for (size_t i = 0; i < row; ++i) {
            std::vector<Complex> rowElements;
            for (size_t j = 0; j < col; ++j) {
                rowElements.push_back(elements[i][j] + other.getElements()[i][j]);
            }
            resultElements.push_back(rowElements);
        }

        return Matrix(row, col, resultElements);
    }

    Matrix operator-(const Matrix& other) const {
        if (row != other.getRow() || col != other.getCol()) {
            std::cout<<"Matrix dimensions must be the same for subtraction.";
        }

        std::vector<std::vector<Complex>> resultElements;
        for (size_t i = 0; i < row; ++i) {
            std::vector<Complex> rowElements;
            for (size_t j = 0; j < col; ++j) {
                rowElements.push_back(elements[i][j] - other.getElements()[i][j]);
            }
            resultElements.push_back(rowElements);
        }

        return Matrix(row, col, resultElements);
    }

    Matrix operator*(const Matrix& other) const {
        if (col != other.getRow()) {
            std::cout<<"Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication.";
        }

        std::vector<std::vector<Complex>> resultElements(row, std::vector<Complex>(other.getCol(), Complex(0, 0)));
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < other.getCol(); ++j) {
                for (size_t k = 0; k < col; ++k) {
                    resultElements[i][j] = resultElements[i][j] + (elements[i][k] * other.getElements()[k][j]);
                }
            }
        }

        return Matrix(row, other.getCol(), resultElements);
    }
    
    
    bool operator==(const Matrix& other) const {
        return (row == other.getRow()) && (col == other.getCol()) && (elements == other.getElements());
    }

    Matrix transpose() const {
        std::vector<std::vector<Complex>> resultElements(col, std::vector<Complex>(row, Complex(0, 0)));
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < col; ++j) {
                resultElements[j][i] = elements[i][j];
            }
        }

        return Matrix(col, row, resultElements);
    }

    double determinant() const {
        if (row != col) {
            std::cout<<"Matrix must be square for determinant calculation.";
            return 0.0;
        }

        // Matrisin boyutu 1 ise, determinantı matrisin tek elemanıdır.
        if (row == 1) {
            return elements[0][0].getReal();
        }

        // Kofaktör genişlemesi yöntemi kullanarak determinantı hesapla
        double det = 0.0;
        for (size_t j = 0; j < col; ++j) {
            // Kofaktör matrisini oluştur
            Matrix cofactorMatrix(row - 1, col - 1, getSubmatrix(0, j));

            
            det += (j % 2 == 0 ? 1 : -1) * elements[0][j].getReal() * cofactorMatrix.determinant();
        }

        return det;
    }

    std::vector<std::vector<Complex>> getSubmatrix(size_t excludeRow, size_t excludeCol) const {
        if (excludeRow >= row || excludeCol >= col) {
        std::cout<<"Exclude row or column is out of range.";
    }
        std::vector<std::vector<Complex>> submatrix;

        for (size_t i = 0; i < row; ++i) {
            if (i == excludeRow) {
                continue;
            }

            std::vector<Complex> rowElements;
            for (size_t j = 0; j < col; ++j) {
                if (j != excludeCol) {
                    rowElements.push_back(elements[i][j]);
                }
            }

            submatrix.push_back(rowElements);
        }

        return submatrix;
    }
    
    
    void print() const {
    
    for (const auto& rowElements : elements) {
        for (const auto& element : rowElements) {
            std::cout << element.getReal() << " + " << element.getImaginary() << "i  ";
        }
        std::cout << std::endl;
    }
}
};

class SquareMatrix : public Matrix {
    
public:
    SquareMatrix(size_t size, double real)
        : Matrix(size, size, generateSquareMatrix(size, real)) {}

private:
    static std::vector<std::vector<Complex>> generateSquareMatrix(size_t size, double initialValue) {
        std::vector<std::vector<Complex>> squareMatrix(size, std::vector<Complex>(size, Complex(0, 0)));
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < size; ++j) {
                squareMatrix[i][j] = Complex(initialValue, 2);
            }
        }
        return squareMatrix;
    }
};

class IdentityMatrix : public Matrix {
public:
    IdentityMatrix(size_t size)
        : Matrix(size,size, generateIdentityMatrix(size)) {}

private:
    static std::vector<std::vector<Complex>> generateIdentityMatrix(size_t size) {
        std::vector<std::vector<Complex>> identityMatrix(size, std::vector<Complex>(size, Complex(0, 0)));
        for (size_t i = 0; i < size; ++i) {
            identityMatrix[i][i] = Complex(1, 0);
        }
        return identityMatrix;
    }
};

class TriangleMatrix : public Matrix {
public:
    TriangleMatrix(size_t size, const std::vector<std::vector<Complex>>& elems)
        : Matrix(size,size, elems) {}


    // Üçgen matrisi alt üçgensel formata dönüştür
    TriangleMatrix toLowerTriangular() const {
        std::vector<std::vector<Complex>> resultElements = getElements();

        for (size_t i = getRow() - 1; i > 0; --i) {
        for (size_t j = i - 1; j < getCol(); --j) {
           Complex factor = Complex(-resultElements[j][i].getReal(), -resultElements[j][i].getImaginary());
            factor = factor / resultElements[i][i];
            for (size_t k = i; k < getCol(); ++k) {
                resultElements[j][k] = resultElements[j][k] + factor * resultElements[i][k];
            }
        }
    }

    return TriangleMatrix(getRow(), resultElements);
}
};


int main() {
    // Complex sınıfı testi
    Complex complex1(1, 2);
    Complex complex2(3, 4);
    Complex complex3 = complex1 + complex2;
    Complex complex4 = complex1 * complex2;
    Complex complex5 = complex1 / complex2;
    Complex complex6 = complex1 - complex2;
    Complex eslenik=complex1.operator~();
    std::cout << "Complex 1: ";
    complex1.print();
    std::cout << "Complex 2: ";
    complex2.print();
    std::cout << "Complex sum: ";
    complex3.print();
    std::cout << "Complex difference: ";
    complex6.print();
    std::cout << "Complex product: ";
    complex4.print();
    std::cout << "Complex quotient: ";
    complex5.print();
    std::cout << "Complex 1 conjuge: ";
    eslenik.print();

    std::cout << "\nBefore += operator complex1: ";
    complex1.print();
    complex1 += complex2;
    std::cout << "After += operator complex1: ";
    complex1.print();

    std::cout << "\nBefore -= operator complex1: ";
    complex1.print();
    complex1 -= complex2;
    std::cout << "After -= operator complex1: " ;
    complex1.print();

    std::cout << "\nBefore *= operator complex1: ";
    complex1.print();
    complex1 *= complex2;
    std::cout << "After *= operator complex1: " ;
    complex1.print();

    std::cout << "\nBefore /= operator complex1: ";
    complex1.print();
    complex1 /= complex2;
    std::cout << "After /= operator complex1: " ;
    complex1.print();
    std::cout<<"**********************************";

    // Vector sınıfı testi
    std::vector<Complex> vec1Elements = {Complex(1, 2), Complex(3, 4), Complex(5, 6)};
    Vector vector1(vec1Elements.size(), vec1Elements);

    std::vector<Complex> vec2Elements = {Complex(7, 8), Complex(9, 10), Complex(11, 12)};
    Vector vector2(vec2Elements.size(), vec2Elements);

    Vector vector3 = vector1 + vector2;
    Vector vector4=vector1-vector2;
    Complex dotProduct = vector1 * vector2;
    //vector1=vector2;

    std::cout << "\nVector 1: ";
    vector1.print();

    std::cout << "Vector 2: ";
    vector2.print();

    std::cout << "Vector sum: ";
    vector3.print();

    std::cout << "Vector difference: ";
    vector4.print();

    std::cout << "Vector product (dot product): " ;
    dotProduct.print();

    //std::cout << "Vector2'yi vector1'e atama: " ;
    //vector1.print();

    
    std::cout << "\nBefore += operator vector1: ";
    vector1.print();
    vector1 += vector2;
    std::cout << "After += operator vector1: " ;
    vector1.print();

    std::cout << "\nBefore -= operator vector1: ";
    vector1.print();
    vector1 -= vector2;
    std::cout << "After -= operator vector1: " ;
    vector1.print();

    std::cout << "\nBefore *= operator vector1: ";
    vector1.print();
    vector1 *= vector2;
    std::cout << "After *= operator vector1: " ;
    vector1.print();

    std::cout << "\nBefore /= operator vector1: ";
    vector1.print();
    vector1 /= vector2;
    std::cout << "After /= operator vector1: " ;
    vector1.print();


    std::cout<<"**********************************";
    // Matrix sınıfı testi
    std::vector<std::vector<Complex>> mat1Elements = {
        {Complex(1, 2), Complex(3, 4),Complex(3, 4)},
        {Complex(5, 6), Complex(7, 8),Complex(3, 4)},
        {Complex(5, 6), Complex(7, 8),Complex(6, 4)}
    };
    Matrix matrix1(mat1Elements.size(), mat1Elements[0].size(), mat1Elements);

    std::vector<std::vector<Complex>> mat2Elements = {
        {Complex(9, 10), Complex(11, 12),Complex(3, 4)},
        {Complex(13, 14), Complex(15, 16),Complex(3, 4)},
        {Complex(17, 18), Complex(19, 20),Complex(3, 4)}
    };
    Matrix matrix2(mat2Elements.size(), mat2Elements[0].size(), mat2Elements);

    Matrix matrix3 = matrix1 + matrix2;
    Matrix matrix4 = matrix1 * matrix2;
    Matrix matrix5 = matrix1 - matrix2;
    bool areEqual = (matrix1 == matrix2);

    
    std::cout << "\nMatrix 1:\n";
    matrix1.print();

    std::cout << "Matrix 2:\n";
    matrix2.print();

    std::cout << "Matrix sum:\n";
    matrix3.print();

    std::cout << "Matrix difference:\n";
    matrix5.print();

    std::cout << "Matrix product:\n";
    matrix4.print();

    std::cout << "Are Matrix 1 and Matrix 2 equal? " << (areEqual ? "Yes" : "No") << std::endl;

    Matrix transposedMatrix = matrix1.transpose(); 
    std::cout << "\nTransposed Matrix1:" << std::endl;
    transposedMatrix.print();

    double det = matrix1.determinant();
    std::cout << "\nDeterminant of the Square Matrix: " << det << std::endl<<std::endl;

    SquareMatrix squareMatrix(4, 2);
    // Oluşturulan SquareMatrix'in içeriğini ekrana yazdırma
    std::cout << "Square Matrix:" << std::endl;
    squareMatrix.print();

    IdentityMatrix identityMatrix(4);
    // Oluşturulan IdentityMatrix'in içeriğini ekrana yazdırma
    std::cout << "Identity Matrix:" << std::endl;
    identityMatrix.print();

    TriangleMatrix triangleMatrix(mat1Elements.size(), mat1Elements);
    // Alt üçgensel formata dönüştür
    TriangleMatrix lowerTriangular = triangleMatrix.toLowerTriangular();
    std::cout << "Lower Triangular Form:" << std::endl;
    lowerTriangular.print();

    

    return 0;
}
