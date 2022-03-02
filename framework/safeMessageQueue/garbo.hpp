#ifndef GARBO_HPP
#define GARBO_HPP

/**
 * Description: This file is used to recycle singleton.
 * Author: Jinboom
 * Date: 2021/8
 */

/**
 * T is a pointer to a singleton.
*/
template <typename T>
class Garbo
{
private:
    /**
     * It must be T&.
     * Because garbo needs to be associated with the single instance to be
     * recycled, if a pointer is used, del is a null pointer when the single
     * instance is not created, and there is no chance to modify it later,
     * so del is always a null pointer, and this problem can be solved by using
     * a pointer reference.
    */
    T &del;

public:
    Garbo() = delete;
    explicit Garbo(T &d) : del(d){};
    Garbo(const Garbo &) = delete;
    Garbo &operator=(const Garbo &) = delete;
    ~Garbo()
    {
        if (del)
        {
            delete del;
            del = nullptr;
        }
    }
};

#endif