#include<iostream>
#include<vector>

class Shape //abstrac base class
{
private:
    //atributes common to all shapes
public:
    virtual void draw() = 0; //pure virtual f-n
    virtual void rotate() = 0; //pure virtual f-n
    virtual ~Shape(){}
};

class OpenShape: public Shape //abstract class
{
public:
    virtual ~OpenShape(){}
};

class ClosedShape: public Shape //abstract class
{
public:
    virtual ~ClosedShape(){}
};

class Line: public OpenShape //concrete class
{
public:
    virtual void draw() override
    {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override
    {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line(){}
};

class Circle: public ClosedShape //concrete class
{
public:
    virtual void draw() override
    {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override
    {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Circle(){}
};

void screen_refresh(const std::vector<Shape *> &ref)
{
    std::cout << "Refreshing" << std::endl;
    for (const auto p: ref)
    {
        p->draw();
        p->rotate();
    }
}

int main()
{
    Shape *pl = new Line();
   // pl->draw();
   // pl->rotate();

    Shape *pc = new Circle();
   // pc->draw();
   // pc->rotate();

    std::vector<Shape *> shapes {pl, pc};
   // for (const auto p: shapes)
   // {
   //     p->draw();
   //     p->rotate();
   // }

    screen_refresh(shapes);

    delete pl;
    delete pc;

    return 0;
}
