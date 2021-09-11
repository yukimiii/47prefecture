#include <iostream>
#include <string>

class onigiri
{
private:
	double _size;
	std::string _type;
public:
	onigiri(double size=0.5, std::string type=""): _size(size), _type(type){}
	onigiri(const onigiri &o){_size=o._size; _type=o._type;}
	~onigiri(){std::cout<<"yummy"<<std::endl;}

	double size()const {return this->_size;}
	std::string type()const {return this->_type;}
	void print()const {std::cout<<_size<<" "+_type;}
	
	const onigiri operator+(const onigiri &r)const{onigiri o; o._size=_size+r._size; o._type=_type+r._type; return o;}
};

std::ostream &operator<<(std::ostream &os, const onigiri &o){
	os<<(o.size()<0.25?"a small":o.size()<=0.5?"a normal":o.size()<=2?"a big":o.size()<=4?"a bomb":"a massive bomb")
		<<" onigiri with "<<o.size()<<" go of rice"<<o.type()<<std::endl;
	return os;
}

int main() {
	onigiri o1(0.2," wrapped by nori"),o2,o3(1," with umeboshi"),o4(2.5," and combu inside");
	std::cout<<"  "<<o1<<"+ "<<o2<<"+ "<<o3<<"+ "<<o4<<"= "<< o1+o2+o3+o4 <<std::endl;
}
