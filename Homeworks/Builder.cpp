#include <iostream>
#include <memory>

class Cake
{
public:
    std::string biscuit;
    std::string cream;
    std::string topping;
    int size;

    void cakeInfo()
    {
        std::cout << "Cake: " << biscuit << ", cream: " << cream << ", topping: " << topping << ", size : " << size << std::endl;
    }
};

class CakeBuilder
{
public:
    virtual void buildBuiscuit() = 0;
    virtual void buildCream() = 0;
    virtual void buildTopping() = 0;
    virtual void buildSize(int size) = 0;
    virtual std::unique_ptr<Cake> getCake() = 0;
};

class VanilaCakeBuilder : public CakeBuilder
{
    std::unique_ptr<Cake> cake;

public:
    VanilaCakeBuilder()
    {
        cake = std::make_unique<Cake>();
    }
    void buildBuiscuit() override
    {
        cake->biscuit = "vanilla";
    }
    void buildCream() override
    {
        cake->cream = "vanilla";
    }
    void buildTopping() override
    {
        cake->topping = "sprinkles";
    }
    void buildSize(int size) override
    {
        cake->size = size;
    };
    std::unique_ptr<Cake> getCake() override
    {
        return std::move(cake);
    }
};

class ChocolateCakeBuilder : public CakeBuilder
{
    std::unique_ptr<Cake> cake;

public:
    ChocolateCakeBuilder()
    {
        cake = std::make_unique<Cake>();
    }
    void buildBuiscuit() override
    {
        cake->biscuit = "chocolate";
    }
    void buildCream() override
    {
        cake->cream = "chocolate";
    }
    void buildTopping() override
    {
        cake->topping = "ganache";
    }
    void buildSize(int size) override
    {
        cake->size = size;
    };
    std::unique_ptr<Cake> getCake() override
    {
        return std::move(cake);
    }
};

class Baker
{
    CakeBuilder *builder;

public:
    void setBuilder(CakeBuilder *builder) { this->builder = builder; }
    std::unique_ptr<Cake> getCake() { return builder->getCake(); }
    void constructCake(int size)
    {
        builder->buildBuiscuit();
        builder->buildCream();
        builder->buildTopping();
        builder->buildSize(size);
    }
};

int main()
{
    Baker baker;

    VanilaCakeBuilder vanilaCakeBuilder;
    baker.setBuilder(&vanilaCakeBuilder);
    baker.constructCake(100);
    std::unique_ptr<Cake> vanilaCake = baker.getCake();
    vanilaCake->cakeInfo();

    ChocolateCakeBuilder chocolateCakeBuilder;
    baker.setBuilder(&chocolateCakeBuilder);
    baker.constructCake(150);
    std::unique_ptr<Cake> chocolateCakeBuilderCake = baker.getCake();
    chocolateCakeBuilderCake->cakeInfo();
}