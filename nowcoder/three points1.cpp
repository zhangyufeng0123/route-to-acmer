#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-12;

struct Point {
    double x, y;
} point[3];

double w, h;

bool judge(double a, double b, double c, int x, int y, int z) {
    point[x].x = 0.0;
    point[x].y = 0.0;
    if (a <= w) {
        point[y].x = a;
        point[y].y = 0;
    } else {
        point[y].x = w;
        point[y].y = sqrt(a * a - w * w);
    }

    double angle = acos((a * a + b * b - c * c) * 1.0 / (2 * a * b));
    angle += atan(point[y].y / point[y].x);

    point[z].x = b * cos(angle);
    point[z].y = b * sin(angle);
    if (point[z].x >= 0 - eps && point[z].x <= w + eps && point[z].y >= 0 - eps && point[z].y <= h + eps) {
        for (int i = 0; i < 2; i++) {
            cout << fixed << setprecision(12) << point[i].x << ' ' << point[i].y << ' ';
        }
        cout << fixed << setprecision(12) << point[2].x << ' ' << point[2].y << endl;
        return true;
    }
    return false;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        double a, b, c;
        cin >> w >> h >> a >> b >> c;
        if (judge(a, b, c, 0, 1, 2)) continue;
        if (judge(a, c, b, 1, 0, 2)) continue;
        if (judge(b, a, c, 0, 2, 1)) continue;
        if (judge(b, c, a, 2, 0, 1)) continue;
        if (judge(c, a, b, 1, 2, 0)) continue;
        if (judge(c, b, a, 2, 1, 0)) continue;
    }
}