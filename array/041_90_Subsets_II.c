#include <stdio.h>
#include <stdlib.h>

// Hàm so sánh dùng cho qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Hàm đệ quy quay lui (Backtracking)
void backtrack(int* nums, int numsSize, int start, int* track, int trackSize, 
               int** res, int* returnSize, int** returnColumnSizes) {
    
    // Cấp phát bộ nhớ lưu tập con hiện tại vào res
    res[*returnSize] = (int*)malloc(sizeof(int) * trackSize);
    for (int i = 0; i < trackSize; i++) {
        res[*returnSize][i] = track[i];
    }
    
    // Lưu độ dài tập con tương ứng
    (*returnColumnSizes)[*returnSize] = trackSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        // Bỏ qua phần tử trùng lặp ở cùng một cấp đệ quy
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }
        
        // Chọn phần tử hiện tại
        track[trackSize] = nums[i];
        
        // Đệ quy cho bước tiếp theo
        backtrack(nums, numsSize, i + 1, track, trackSize + 1, res, returnSize, returnColumnSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // 1. Sắp xếp mảng để gom các phần tử trùng lại gần nhau
    qsort(nums, numsSize, sizeof(int), cmp);

    // 2. Số lượng tập con tối đa là 2^numsSize
    int maxSubsets = 1 << numsSize; 
    
    int** res = (int**)malloc(sizeof(int*) * maxSubsets);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxSubsets);
    
    // Mảng tạm để lưu trạng thái tập con hiện tại
    int* track = (int*)malloc(sizeof(int) * numsSize);
    
    *returnSize = 0;

    // 3. Gọi hàm đệ quy
    backtrack(nums, numsSize, 0, track, 0, res, returnSize, returnColumnSizes);

    // Giải phóng bộ nhớ mảng tạm
    free(track);
    
    return res;
}