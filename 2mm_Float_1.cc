#include <ap_int.h>
#include <ap_fixed.h>
#include <ap_axi_sdata.h>
#include <hls_stream.h>
#include <hls_math.h>
#include <math.h>
#include <stdint.h>
void default_function(float A[16][22], float B[22][18], float C[18][24], float D[16][24]) {
  float _top;
  float out_AB[16][18];
  out_AB_x: for (int x = 0; x < 16; ++x) {
    out_AB_y: for (int y = 0; y < 18; ++y) {
      float sum;
      sum_x1: for (int x1 = 0; x1 < 1; ++x1) {
        sum = 0.000000e+00f;
      }
      out_AB_r: for (int r = 0; r < 22; ++r) {
        sum = ((A[x][r] * B[r][y]) + sum);
      }
      out_AB[x][y] = sum;
    }
  }
  float out_ABC[16][24];
  out_ABC_x2: for (int x2 = 0; x2 < 16; ++x2) {
    out_ABC_y1: for (int y1 = 0; y1 < 24; ++y1) {
      float sum_;
      sum_x3: for (int x3 = 0; x3 < 1; ++x3) {
        sum_ = 0.000000e+00f;
      }
      out_ABC_k: for (int k = 0; k < 18; ++k) {
        sum_ = ((out_AB[x2][k] * C[k][y1]) + sum_);
      }
      out_ABC[x2][y1] = sum_;
    }
  }
  float D1;
  D_x4: for (int x4 = 0; x4 < 16; ++x4) {
    D_y2: for (int y2 = 0; y2 < 24; ++y2) {
      D[x4][y2] = ((out_ABC[x4][y2] + D[x4][y2]) * 1.000000e-01f);
    }
  }
}

int main() {
    float A[16][22];
    float B[22][18];
    float C[18][24];
    float D[16][24];

    default_function(A, B, C, D);

    return 0;
}

