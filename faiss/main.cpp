#include <iostream>
#include <vector>
#include <cassert>
#include <faiss/IndexFlat.h>
#include <faiss/IndexIVF.h>
#include <faiss/IndexLSH.h>

// int main() {
//     // Tạo dữ liệu mẫu
//     std::vector<float> data = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0,
//                                7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
//     int n = 3;  // số lượng vector
//     int d = 4;  // số chiều của mỗi vector

//     // Tạo index
//     faiss::IndexFlatL2 index(d);  // sử dụng khoảng cách Euclid
//     assert(index.is_trained);
//     index.add(n, data.data());

//     // Tìm kiếm vector độ lớn gần nhất
//     int k = 2;  // số lượng kết quả tìm kiếm
//     std::vector<float> query = {1.5, 3.5, 5.5, 7.5};  // vector tìm kiếm
//     std::vector<int64_t> I(k);
//     std::vector<float> D(k);
//     index.search(1, query.data(), k, D.data(), I.data());

//     // In kết quả tìm kiếm
//     std::cout << "Ket qua tim kiem:" << std::endl;
//     for (int i = 0; i < k; i++) {
//         std::cout << "Vector " << I[i] << " - Khoang cach: " << D[i] << std::endl;
//     }

//     return 0;
// }

#include <faiss/IndexFlat.h>

#include <iostream>
#include <vector>
#include <faiss/IndexFlat.h>
#include <faiss/VectorTransform.h>

using namespace std;

int main() {
  // Tạo ra một mảng chứa các vector
  float* trainData = new float[10];
  for (int i = 0; i < 10; ++i) {
    *(trainData + i) = i + 1.0;
  }

  // Chuyển đổi mảng vector thành ma trận và lưu trữ trong đối tượng faiss::IndexFlatL2
  faiss::IndexFlatL2 index(2);
  index.add(2, trainData);

  // Tìm kiếm vector gần nhất
  float* query = new float[6];
  for (int i = 0; i < 6; ++i) {
    *(query + i) = i + 2.0;
  }
  float* distances = new float[2];
  int64_t* labels = new int64_t[2];
  index.search(2, query, 2, distances, labels);

  // In ra kết quả
  cout << "Distances: " << endl;
  for (int i = 0; i < 2; ++i) {
    cout << *(distances + i) << " ";
  }
  cout << endl;

  cout << "Labels: " << endl;
  for (int i = 0; i < 2; ++i) {
    cout << *(labels + i) << " ";
  }
  cout << endl;

  // Giải phóng bộ nhớ đã được cấp phát
  delete[] trainData;
  delete[] query;
  delete[] distances;
  delete[] labels;

  return 0;
}