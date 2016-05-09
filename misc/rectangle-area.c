int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int ret = (C - A) * (D - B) + (G - E) * (H - F);
    int x0 = A > E ? A : E;
    int y0 = B > F ? B : F;
    int x1 = C < G ? C : G;
    int y1 = D < H ? D : H;

    if(x1 <= x0 || y1 <= y0)
        return ret;

    return ret - (x1 - x0) * (y1 - y0);
}
