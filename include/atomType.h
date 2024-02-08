#ifndef ATOMTYPE_H
#define ATOMTYPE_H

#include <cstdint>
#include <list>
#include <vector>

namespace calculus
{
    enum atom_opp
    {
        atom_plus = 0b0000'1111,
        atom_minus = 0b0001'1111,
        atom_mul = 0b0010'1111,
        atom_div = 0b0011'1111,
        atom_pow = 0b0100'1111,
        atom_fact = 0b0101'1111
    };




    struct atom_t
    {
        // 0000 | 0000
        // ---- | ----
        //  up    down
        uint8_t data;


        [[nodiscard]] uint8_t getUp() const
        {
            return (this->data & 0b11110000) >> 4;
        }

        [[nodiscard]] uint8_t getDown() const
        {
            return this->data & 0b00001111;
        }

        void setUp(const uint8_t value)
        {
            this->data = (this->data & 0b00001111) | (value << 4);
        }

        void setDown(const uint8_t value)
        {
            this->data = (this->data & 0b11110000) | (value);
        }

        void setSpecial(const atom_opp key)
        {
            this->data = key;
        }

    };

    inline size_t size_vector_atom_single(const std::vector<calculus::atom_t> &vec_atom)
    {
        const size_t size = vec_atom.size();
        if (vec_atom[0].getUp() == 0)
        {
            return (size*2)-1;
        }
        return size*2;
    }

    inline size_t size_list_atom_single(const std::list<calculus::atom_t> &vec_atom)
    {
        const size_t size = vec_atom.size();
        if (vec_atom.front().getUp() == 0)
        {
            return (size*2)-1;
        }
        return size*2;
    }





}

#endif //ATOMTYPE_H
