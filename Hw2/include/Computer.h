/* @Author
 * Student Name:    Helin Aslı Askoy
 */
#include <iostream>
#include <cstdio>

class ALU
{
public:
    ALU();
    int getNumPerCores();
    void setNumPerCores(int);
    void add() const;
    void subtract() const;
    void multiply() const;
    ~ALU();

private:
    int numPerCores;
};

class CUDA
{
public:
    CUDA();
    int getNumCores();
    void setNumCores(int);
    void render() const;
    void trainModel() const;
    ~CUDA();

private:
    int numCores;
};

class CPU
{
public:
    CPU(int);
    ALU getAlu();
    void executeCPU(std::string) const;
    ~CPU();

private:
    ALU alu;
};

class GPU
{
public:
    GPU(int);
    CUDA getCuda();
    void executeGPU(std::string) const;
    ~GPU();

private:
    CUDA cuda;
};

class Computer
{
public:
    Computer();
    const CPU *getAttachedCPU();
    const GPU *getAttachedGPU();
    void execute(std::string);
    void operator+(const CPU &);
    void operator+(const GPU &);
    ~Computer();

private:
    const CPU *attachedCPU;
    const GPU *attachedGPU;
};
