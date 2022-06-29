#ifndef FE0C20F3603C4B6B9DBF2214C001D90A
#define FE0C20F3603C4B6B9DBF2214C001D90A

// 一些动作宏
#define TURN_LEFT "turn left"
#define TURN_RIGHT "turn right"
#define FORWARD "forward"
#define BACKWARD "backward"
#define TURN_ROUND "turn round"
#define NORTH "北"
#define EAST "东"
#define WEST "西"
#define SOUTH "南"

// 一些命名宏
#define X 0
#define Y 1

#include <string>
#include <map>

typedef struct _init_pack {
    int x;
    int y;
    std::string heading;
} init_pack;

typedef struct _attr {
    std::string heading;
    bool XorY;
    int op;
} attr;

typedef struct _position {
    int position_x;
    int position_y;
    int heading_code;    // 北1000 东0100 南0010 西0001
    std::map<int, attr> heading_attribute;
    std::map<std::string, int> heading_to_code;
    // turn left ((heading_code << 1) & 0b1111) | (heading_code >> 4)
    // turn right (heading_code >> 1) | ((heading_code << 3) & 0b1111)
} position;

typedef struct _position_readable {
    int x;
    int y;
    std::string heading;
    friend bool operator==(_position_readable p, _position_readable q) {
        if (p.x == q.x && p.y == q.y && p.heading == q.heading) return true;
        else return false;
    }
} position_readable;

class Executor {
public:
    explicit Executor(std::string name) : name(std::move(name))
    {
        init();
    }

    explicit Executor() {
        name = "Default name";
        init();
    }

    const std::string& get_name() const
    {
        return name;
    }
    
    bool init(init_pack init_pk = {0, 0, NORTH});
    bool take_action(std::string action);
    position_readable get_position();
    void move(int forward_or_backward);

private:
    std::string name;
    position pos;
};

#endif //FE0C20F3603C4B6B9DBF2214C001D90A
