class ParkingSystem {
private:
    int m_big, m_medium, m_small;
public:
    ParkingSystem(int big, int medium, int small) : 
        m_big(big),
        m_medium(medium),
        m_small(small) {}
    bool addCar(int carType) {
        switch (carType) {
            case 1:
                if (m_big > 0) {
                    --m_big;
                    return true;
                }
                return false;
            case 2:
                if (m_medium > 0) {
                    --m_medium;
                    return true;
                }
                return false;
            case 3:
                if (m_small > 0) {
                    --m_small;
                    return true;
                }
                return false;
            default:
                break;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */