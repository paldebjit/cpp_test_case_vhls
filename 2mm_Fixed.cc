#include <ap_int.h>
#include <ap_fixed.h>
#include <ap_axi_sdata.h>
#include <hls_stream.h>
#include <hls_math.h>
#include <math.h>
#include <stdint.h>
void default_function(ap_fixed<13, 8> A[16][22], ap_fixed<13, 8> B[22][18], ap_fixed<13, 8> C[18][24], ap_fixed<13, 8> D[16][24]) {
  ap_fixed<13, 8> _top;
  ap_fixed<13, 8> out_AB[16][18];
  out_AB_x: for (int x = 0; x < 16; ++x) {
    out_AB_y: for (int y = 0; y < 18; ++y) {
      ap_fixed<13, 8> sum;
      sum_x1: for (int x1 = 0; x1 < 1; ++x1) {
        sum = ((ap_fixed<13, 8>)0);
      }
      out_AB_r: for (int r = 0; r < 22; ++r) {
        sum = ((ap_fixed<13, 8>)(((ap_fixed<27, 17>)(((ap_fixed<26, 21>)A[x][r]) * ((ap_fixed<26, 21>)B[r][y]))) + ((ap_fixed<27, 17>)sum)));
      }
      out_AB[x][y] = sum;
    }
  }
  ap_fixed<13, 8> out_ABC[16][24];
  out_ABC_x2: for (int x2 = 0; x2 < 16; ++x2) {
    out_ABC_y1: for (int y1 = 0; y1 < 24; ++y1) {
      ap_fixed<13, 8> sum_;
      sum_x3: for (int x3 = 0; x3 < 1; ++x3) {
        sum_ = ((ap_fixed<13, 8>)0);
      }
      out_ABC_k: for (int k = 0; k < 18; ++k) {
        sum_ = ((ap_fixed<13, 8>)(((ap_fixed<27, 17>)(((ap_fixed<26, 21>)out_AB[x2][k]) * ((ap_fixed<26, 21>)C[k][y1]))) + ((ap_fixed<27, 17>)sum_)));
      }
      out_ABC[x2][y1] = sum_;
    }
  }
  ap_fixed<13, 8> D1;
  D_x4: for (int x4 = 0; x4 < 16; ++x4) {
    D_y2: for (int y2 = 0; y2 < 24; ++y2) {
      D[x4][y2] = ((ap_fixed<13, 8>)((((float)out_ABC[x4][y2]) + ((float)D[x4][y2])) * 1.000000e-01f));
    }
  }
}

int main() {
    ap_fixed<13, 8> A[16][22];
    ap_fixed<13, 8> B[22][18];
    ap_fixed<13, 8> C[18][24];
    ap_fixed<13, 8> D[16][24];

    default_function(A, B, C, D);

    return 0;
}


