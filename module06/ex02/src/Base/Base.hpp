#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
	virtual ~Base();
};

class A : public Base{ virtual ~A(); };
class B : public Base{ virtual ~B(); };
class C : public Base{ virtual ~C(); };

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif