#include <iostream>
using namespace std;

class Fueltank {
    private:
        int m_FueltankCapacity;
        int m_gas_grade;
    public:
        Fueltank(int FueltankCapacity = 300, int Gas = 98) {
            m_FueltankCapacity = FueltankCapacity;
            m_gas_grade = Gas;
        }
        int fuel_up(int n, int gas){
            if (gas != m_gas_grade){
                cout << "Error: Gas_grade: " << gas << " Correct Gas_grade: " << m_gas_grade << endl;
            }
            else if (n > m_FueltankCapacity){
                cout << "Error: FueltankCapacity: " << m_FueltankCapacity << " but fuel up: " << n << endl;
            }
            else {
                cout << "fuel_up: " << n << " Gas_Grade: " << m_gas_grade;
            }
            return 0;
        }
        int set_gas_grade(int Gas_grade){
            m_gas_grade = Gas_grade;
            cout << "Set Gas_grade: " << m_gas_grade << endl;
            return 0;
        }
        int get_gas_grade(){
            return m_gas_grade;   
        }
};

class Car {
    private:
        Fueltank m_Fueltank;
        string m_brand;
    public:
        string get_brand(){
            return m_brand;
        }
        int get_gas_grade(){
            return m_Fueltank.get_gas_grade();
        };
        int set_gas_grade(int gas = 98){
            m_Fueltank.set_gas_grade(gas);
            return 0;
        }
        int fuel_up(int v, int gas = 98){
            m_Fueltank.fuel_up(v, gas);
            return 0;
        }
};

class AUDI_Car : public Car {
    private:
        Fueltank m_Fueltank;
        string m_brand = "AUDI";
    public:
        string get_brand(){
            return m_brand;
        }
        int get_gas_grade(){
            return m_Fueltank.get_gas_grade();
        }
        int set_gas_grade(int gas = 98){
            m_Fueltank.set_gas_grade(gas);
            return 0;
        }
        int fuel_up(int v, int gas = 98){
            m_Fueltank.fuel_up(v, gas);
            return 0;
        }
};

int main() {
    AUDI_Car car_2;
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_gas_grade() << endl;
    car_2.set_gas_grade(95);
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_gas_grade() << endl;
    car_2.fuel_up(3000, 95);

    return 0;
}