#include <ap_int.h>
#include <ap_fixed.h>
#include <ap_axi_sdata.h>
#include <hls_stream.h>
#include <hls_math.h>
#include <math.h>
#include <stdint.h>
void default_function(ap_uint<24> A[16][22], ap_uint<24> B[22][18], ap_uint<24> C[18][24], ap_uint<24> D[16][24]) {
  ap_uint<24> _top;
  ap_uint<24> out_AB[16][18];
  out_AB_x: for (int x = 0; x < 16; ++x) {
    out_AB_y: for (int y = 0; y < 18; ++y) {
      ap_uint<24> sum;
      sum_x1: for (int x1 = 0; x1 < 1; ++x1) {
        sum = (ap_uint<24>)0;
      }
      out_AB_r: for (int r = 0; r < 22; ++r) {
        sum = ((ap_uint<24>)(((ap_uint<49>)(((ap_uint<48>)A[x][r]) * ((ap_uint<48>)B[r][y]))) + ((ap_uint<49>)sum)));
      }
      out_AB[x][y] = sum;
    }
  }
  ap_uint<24> out_ABC[16][24];
  out_ABC_x2: for (int x2 = 0; x2 < 16; ++x2) {
    out_ABC_y1: for (int y1 = 0; y1 < 24; ++y1) {
      ap_uint<24> sum_;
      sum_x3: for (int x3 = 0; x3 < 1; ++x3) {
        sum_ = (ap_uint<24>)0;
      }
      out_ABC_k: for (int k = 0; k < 18; ++k) {
        sum_ = ((ap_uint<24>)(((ap_uint<49>)(((ap_uint<48>)out_AB[x2][k]) * ((ap_uint<48>)C[k][y1]))) + ((ap_uint<49>)sum_)));
      }
      out_ABC[x2][y1] = sum_;
    }
  }
  ap_uint<24> D1;
  D_x4: for (int x4 = 0; x4 < 16; ++x4) {
    D_y2: for (int y2 = 0; y2 < 24; ++y2) {
      D[x4][y2] = ((ap_uint<24>)((((float)out_ABC[x4][y2]) + ((float)D[x4][y2])) * 1.000000e-01f));
    }
  }
}

int main() {
    ap_uint<24> A[16][22];
    ap_uint<24> B[22][18];
    ap_uint<24> C[18][24];
    ap_uint<24> D[16][24];

    default_function(A, B, C, D);

    return 0;
}



