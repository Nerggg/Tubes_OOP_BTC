#ifndef __PLAYER_HPP
#define __PLAYER_HPP

class Player {
    protected:

    public:
        virtual void hitungPajak();

};

class Walikota : public Player {
    protected:

    public:
        void hitungPajak();
};

class Petani : public Player {
    protected:

    public:
        void hitungPajak();
};

class Peternak : public Player {
    protected:

    public:
        void hitungPajak();
};

#endif