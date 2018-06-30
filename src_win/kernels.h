#pragma once
#include "common.h"
#include <float.h>

namespace SCRIMP {


SCRIMPError_t kernel_self_join_upper(const double *QT, const double *timeseries_A, const double *timeseries_B, const double *df_A, const double *df_B, const double *dg_A, const double *dg_B, const double *norms_A, const double *norms_B, unsigned long long int *profile_A, unsigned long long int *profile_B, size_t window_size, size_t tile_width, size_t tile_height, size_t global_x, size_t global_y, const cudaDeviceProp &props, bool fp64, cudaStream_t s);

SCRIMPError_t kernel_self_join_lower(const double *QT, const double *timeseries_A, const double *timeseries_B, const double *df_A, const double *df_B, const double *dg_A, const double *dg_B, const double *norms_A, const double *norms_B, unsigned long long int *profile_A, unsigned long long int *profile_B, size_t window_size, size_t tile_width, size_t tile_height, size_t global_x, size_t global_y, const cudaDeviceProp &props, bool fp64, cudaStream_t s);

SCRIMPError_t kernel_ab_join_upper(const double *QT, const double *timeseries_A, const double *timeseries_B, const double *df_A, const double *df_B, const double *dg_A, const double *dg_B, const double *norms_A, const double *norms_B, unsigned long long int *profile_A, unsigned long long int *profile_B, size_t window_size, size_t tile_width, size_t tile_height, size_t global_x, size_t global_y, size_t global_start_x, size_t global_start_y, const cudaDeviceProp &props, bool fp64, bool full_join, cudaStream_t s);

SCRIMPError_t kernel_ab_join_lower(const double *QT, const double *timeseries_A, const double *timeseries_B, const double *df_A, const double *df_B, const double *dg_A, const double *dg_B, const double *norms_A, const double *norms_B, unsigned long long int *profile_A, unsigned long long int *profile_B, size_t window_size, size_t tile_width, size_t tile_height, size_t global_x, size_t global_y, size_t global_start_x, size_t global_start_y, const cudaDeviceProp &props, bool fp64, bool full_join, cudaStream_t s);
}
