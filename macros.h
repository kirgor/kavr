#define NARGS_(_1, _2, _3, _4, _5, _6, _7, _8, N, ...) N
#define NARGS(...) NARGS_(__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1)

#define mask1(b1) (1<<b1)
#define mask2(b1,b2) (1<<b1)|(1<<b2)
#define mask3(b1,b2,b3) (1<<b1)|(1<<b2)|(1<<b3)
#define mask4(b1,b2,b3,b4) (1<<b1)|(1<<b2)|(1<<b3)|(1<<b4)
#define mask5(b1,b2,b3,b4,b5) (1<<b1)|(1<<b2)|(1<<b3)|(1<<b4)|(1<<b5)
#define mask6(b1,b2,b3,b4,b5,b6) (1<<b1)|(1<<b2)|(1<<b3)|(1<<b4)|(1<<b5)|(1<<b6)
#define mask7(b1,b2,b3,b4,b5,b6,b7) (1<<b1)|(1<<b2)|(1<<b3)|(1<<b4)|(1<<b5)|(1<<b6)|(1<<b7)
#define mask8(b1,b2,b3,b4,b5,b6,b7,b8) (1<<b1)|(1<<b2)|(1<<b3)|(1<<b4)|(1<<b5)|(1<<b6)|(1<<b7)|(1<<b8)
#define mask__(count, ...) mask ## count (__VA_ARGS__)
#define mask_(count, ...) mask__(count, __VA_ARGS__)
#define mask(...) mask_(NARGS(__VA_ARGS__), __VA_ARGS__)
#define setFlags(var, ...) var |= mask(__VA_ARGS__)
#define setFlag(var, flag) setFlags(var, flag)
#define unsetFlags(var, ...) var &= ~(mask(__VA_ARGS__))
#define unsetFlag(var, flag) unsetFlags(var, flag)
#define checkFlag(var, flag) (var&(1<<flag))
