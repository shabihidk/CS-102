#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

class DonutRenderer {
private:
    float a, b;
    int height, width, buffer_size;
    float *zBuffer;
    char *output;

public:
    DonutRenderer(int h, int w) : height(h), width(w), buffer_size(h * w) {
        zBuffer = new float[buffer_size];
        output = new char[buffer_size];
        a = b = 0;
    }

    ~DonutRenderer() {
        delete[] zBuffer;
        delete[] output;
    }

    void display() {
        printf("\x1b[H");
        for (int i = 0; i < buffer_size; i++) {
            putchar(i % width ? output[i] : 10);
            a += 0.00004;
            b += 0.00002;
        }
    }

    void render() {
        int outer_size = width / 40;
        int lum_digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        memset(output, ' ', buffer_size);
        memset(zBuffer, 0, buffer_size * sizeof(float));

        for (float theta = 0; theta < 6.28; theta += 0.07) {
            for (float phi = 0; phi < 6.28; phi += 0.02) {
                float sinPhi = sin(phi);
                float cosTheta = cos(theta);
                float sinA = sin(a);
                float sinTheta = sin(theta);
                float cosA = cos(a);
                float circleX = cosTheta + outer_size;
                float circleY = sinPhi * circleX * cosA - sinTheta * sinA;
                float norm_z = 1 / (sinPhi * circleX * sinA + sinTheta * cosA + 5);
                float cosPhi = cos(phi);
                float cosB = cos(b);
                float sinB = sin(b);
                int x = (width / 2) + 30 * norm_z * (cosPhi * circleX * cosB + circleY * sinB);
                int y = (height / 2 + 1) + 15 * norm_z * (cosPhi * circleX * sinB - circleY * cosB);
                int o = x + width * y;
                float lum = 8 * ((sinTheta * sinA - sinPhi * cosTheta * cosA) * cosB - sinPhi * cosTheta * sinA - sinTheta * cosA - cosPhi * cosTheta * sinB);
                if (height > y && y > 0 && x > 0 && width > x && norm_z > zBuffer[o]) {
                    zBuffer[o] = norm_z;
                    output[o] = '0' + lum_digits[(int)fmod(lum, 10)];
                }
            }
        }
    }

    void run() {
        printf("\x1b[2J");
        for (;;) {
            render();
            display();
        }
    }
};

int main() {
    int height = 22;
    int width = 80;
    DonutRenderer renderer(height, width);
    renderer.run();
    return 0;
}

