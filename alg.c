#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define NONE 0


typedef uint64_t Span;


typedef enum {
    Left,
    Right,
    Middle,
    ChildCount
} Child;


typedef struct {
    uint32_t x, y;
    uint32_t w, h;
} Info;

typedef struct {
    Info maxW;
    Info maxH;
    Info maxS;

    int next;
} Area;

typedef struct {
    uint32_t x, y;
    uint32_t w, h;

    int id;

    Area areas[3];
} Rect;

typedef struct {
    int index;
    Child child;
} Place;


static inline int max(uint32_t a, uint32_t b)
{
    return a > b ? a : b;
}

static inline Span getSpan(uint32_t w, uint32_t h)
{
    if (h > w) {
        uint32_t t = w;
        w = h;
        h = t;
    }

    return ((uint64_t)w << 32) | h;
}

static inline int fits(uint32_t w1, uint32_t h1, uint32_t w2, uint32_t h2)
{
    return w1 <= w2 && h1 <= h2;
}

static inline Place search(int searcher, int searchee, Rect *rects)
{
    
}

static inline void packRect(int index, Rect *rects)
{
    
}

void packRects(Rect *rects, int rectCount)
{
    rects[0].x = 0;
    rects[0].y = 0;

    Info info;

    info.x = rects[0].w;
    info.y = 0;
    info.w = INT_MAX;
    info.h = rects[0].h;

    rects[0].areas[Left].maxW = info;
    rects[0].areas[Left].maxH = info;
    rects[0].areas[Left].maxS = info;
    rects[0].areas[Left].next = NONE;

    info.x = 0;
    info.y = rects[0].h;
    info.w = rects[0].w;
    info.h = INT_MAX;

    rects[0].areas[Right].maxW = info;
    rects[0].areas[Right].maxH = info;
    rects[0].areas[Right].maxS = info;
    rects[0].areas[Right].next = NONE;

    info.x = rects[0].w;
    info.y = rects[0].h;
    info.w = INT_MAX;
    info.h = INT_MAX;

    rects[0].areas[Middle].maxW = info;
    rects[0].areas[Middle].maxH = info;
    rects[0].areas[Middle].maxS = info;
    rects[0].areas[Middle].next = NONE;

    for (int i = 1; i < rectCount; i++) {
        packRect(i, rects);
    }
}

int main()
{
    const int rectCount = 1000;
    const uint32_t maxSpan = 20;
    const uint32_t minSpan = 5;

    Rect *rects = malloc(rectCount * sizeof(Rect));
    for (int i = 0; i < rectCount; i++) {
        rects[i].w = minSpan + (rand() % (maxSpan - minSpan));
        rects[i].h = minSpan + (rand() % (maxSpan - minSpan));
        rects[i].id = i;
    }

    packRects(rects, rectCount);

    free(rects);
    return 0;
}

