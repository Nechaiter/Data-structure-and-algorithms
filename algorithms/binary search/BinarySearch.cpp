// https://leetcode.com/problems/binary-search/

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        // int tamanio_array = sizeof(nums) / sizeof(int);
        int tamanio_array = nums.size();
        int inicio = {0};
        int final = {tamanio_array - 1};
        while (inicio <= final) {
            int mitad = (final + inicio) / 2;
            // Busqueda por derecha
            if (nums[mitad] > target) {
                final = mitad - 1;

                continue;
            }
            // busqueda por la izquierda
            else if (nums[mitad] < target) {
                inicio = mitad + 1;
                continue;
            }
            return mitad;
        }
        return -1;
    };
};