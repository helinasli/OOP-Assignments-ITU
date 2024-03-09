/* @Author
 * Student Name:    Helin Aslı Askoy
 */
#include "Computer.h"

// ALU Constructor
ALU::ALU()
{
    std::cout << "ALU is ready" << std::endl;
}

int ALU::getNumPerCores()
{
    return this->numPerCores;
}

void ALU::setNumPerCores(int var)
{
    this->numPerCores = var;
}

// Perform add operation
void ALU::add() const
{
    int var1, var2;
    std::cout << "Enter two integers" << std::endl;
    std::cin >> var1;
    std::cin >> var2;
    std::cout << var1 + var2 << std::endl;
}

// Perform subtract operation
void ALU::subtract() const
{
    int var1, var2;
    std::cout << "Enter two integers" << std::endl;
    std::cin >> var1;
    std::cin >> var2;
    std::cout << var1 - var2 << std::endl;
}

// Perform multiplication operation
void ALU::multiply() const
{
    int var1, var2;
    std::cout << "Enter two integers" << std::endl;
    std::cin >> var1;
    std::cin >> var2;
    std::cout << var1 * var2 << std::endl;
}

ALU::~ALU()
{
}

//  Cuda Constructor
CUDA::CUDA()
{
    std::cout << "CUDA is ready" << std::endl;
}

int CUDA::getNumCores()
{
    return this->numCores;
}

void CUDA::setNumCores(int var)
{
    this->numCores = var;
}

// Perform rendering operation
void CUDA::render() const
{
    std::cout << "Video is rendered" << std::endl;
}

// Train AI model
void CUDA::trainModel() const
{
    std::cout << "AI Model is trained" << std::endl;
}

CUDA::~CUDA()
{
}

// CPU Constructor
CPU::CPU(int numPerCores)
{
    std::cout << "CPU is ready" << std::endl;
    this->alu.setNumPerCores(numPerCores);
}

ALU CPU::getAlu()
{
    return this->alu;
}

// Execute ALU operation based on the input string
void CPU::executeCPU(std::string var) const
{
    if (var == "add")
    {
        this->alu.add();
    }
    else if (var == "subtract")
    {
        this->alu.subtract();
    }
    else if (var == "multiply")
    {
        this->alu.multiply();
    }
}

CPU::~CPU()
{
}

// GPU Constructor
GPU::GPU(int numPerCores)
{
    std::cout << "GPU is ready" << std::endl;
    this->cuda.setNumCores(numPerCores);
}

CUDA GPU::getCuda()
{
    return this->cuda;
}

// Execute CUDA operation based on the input string
void GPU::executeGPU(std::string var) const
{
    if (var == "render")
    {
        this->cuda.render();
    }
    else if (var == "trainModel")
    {
        this->cuda.trainModel();
    }
}

GPU::~GPU()
{
}

// Computer constructor
Computer::Computer()
{
    this->attachedCPU = nullptr;
    this->attachedGPU = nullptr;
    std::cout << "Computer is ready" << std::endl;
}

const CPU *Computer::getAttachedCPU()
{
    return this->attachedCPU;
}
const GPU *Computer::getAttachedGPU()
{
    return this->attachedGPU;
}

// Execute CPU or GPU operation based on the input string
void Computer::execute(std::string var)
{
    if (var == "add" || var == "subtract" || var == "multiply")
    {
        this->getAttachedCPU()->executeCPU(var);
    }
    else if (var == "render" || var == "trainModel")
    {
        this->getAttachedGPU()->executeGPU(var);
    }
}

void Computer::operator+(const CPU &obj)
{
    // Check current cpu and gpu is absent?
    if (this->attachedCPU != nullptr)
    {
        std::cout << "There is already a CPU" << std::endl;
    }
    else
    {
        this->attachedCPU = &obj;
        std::cout << "CPU is attached" << std::endl;
    }
    // Assign the paramater objects variables to our object
}

void Computer::operator+(const GPU &obj)
{
    // Check current cpu and gpu is absent?
    if (this->attachedGPU != nullptr)
    {
        std::cout << "There is already a GPU" << std::endl;
    }
    else
    {
        this->attachedGPU = &obj;
        std::cout << "GPU is attached" << std::endl;
    }
    // Assign the paramater objects variables to our object
}

Computer::~Computer()
{
}