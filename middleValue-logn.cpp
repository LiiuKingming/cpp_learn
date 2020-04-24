double midVal(vector<int>& nums1, int n1, vector<int>& nums2, int n2) {
    // 保证在短数组求解
    if (n1 > n2) {
        return midVal(nums2, n2, nums1, n1);
    }

    if (n1 == 0) {
        int mid = (n2 - 1) / 2;
        if (n2 % 2 == 0) {
            return (nums2[mid] + nums2[mid + 1]) * 1.0 / 2;
        } else {
            return nums2[mid];
        }
    }

    int i = 0;
    int j = 0;
    int begin = 0;
    int end = n1;
    int mid = (n1 + n2 + 1) / 2;
    while (begin <= end) {
        i = (begin + end) / 2;
        j = mid - i;
        if (i > 0 && j < n2 && nums1[i - 1] > nums2[j]) {
            //缩小nums1范围找到nums1[i - 1] < nums2[j]
            end = i - 1;
        } else if (j > 0 && i < n1 && nums2[j - 1] > nums1[i]) {
            //缩小nums1范围找到nums2[j - 1] < nums1[i]
            begin = i + 1;
        } else {
            // 找到i, j就跳出
            break;
        }
    }

    int left = 0;
    if (i == 0) {
        left = nums2[j - 1];
    } else if (j == 0) {
        left = nums1[i - 1];
    } else {
        left = max(nums1[i - 1], nums2[j - 1]);
    }

    if ((n1 + n2) % 2 != 0) { // 奇数
        return left;
    } else { // 偶数
        int right = 0;
        if (i == n1) {
            right = nums2[j];
        } else if (j == n2) {
            right = nums1[i];
        } else {
            right = min(nums1[i], nums2[j]);
        }

        return (left + right) * 1.0 / 2;
    }
}