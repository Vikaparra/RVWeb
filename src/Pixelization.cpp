#include "Pixelization.hpp"

// HACK: We can probably improve efficiency by removing one or two steps before
// this.
void Pixelization::generatePixelizatedMatrix(
    std::vector<std::vector<std::vector<double>>> &data) {
  // std::vector<std::vector<std::vector<double>>> final;
  // std::vector<std::vector<double>> clusterOfModels;
  // std::vector<double> model;
  // std::vector<double> intermediary;
  // std::vector<std::vector<double>> intermediarySecond;
  //
  // for (int i = 0; i < itr->second.size(); i++) {
  //   for (const auto &pair : data) {
  //     model.push_back(pair.second.at(i));
  //   }
  //   clusterOfModels.push_back(model);
  //   model.clear();
  // }
  //
  // for (int j = 0; j < clusterOfModels.size(); j++) {
  //   for (int i = 0; i < clusterOfModels.at(0).size(); i++) {
  //     intermediary.push_back(clusterOfModels.at(j).at(i));
  //     if ((i + 1) % 3 == 0) {
  //       intermediarySecond.push_back(intermediary);
  //       intermediary.clear();
  //     }
  //     std::cout << clusterOfModels.at(j).at(i);
  //     ((i + 1) % 3 == 0) ? std::cout << std::endl : std::cout << " - ";
  //   }
  //   final.push_back(intermediarySecond);
  //   intermediarySecond.clear();
  //   std::cout << std::endl;
  // }
  //
  // std::cout << final.size() << std::endl;
  // std::cout << final.at(0).size() << std::endl;
  // std::cout << final.at(0).at(0).size() << std::endl;
  //
  std::ofstream finalFile("final1.csv");

  for (int i = 0; i < data.at(0).size(); i++) {
    for (int j = 0; j < data.size(); j++) {
      for (int k = 0; k < data.at(0).at(0).size(); k++) {
        finalFile << data.at(i).at(j).at(k) << ';';
      }
      if ((j + 1) % 3 == 0) {
        finalFile << "\n";
      }
    }
    //    std::cout << std::endl;
    //    finalFile << "\n";
  }

  // int size = test.at(0).size();
  // for (int i = 0; i < 27; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     std::cout << test.at(i).at(0) << " - ";
  //     test.at(i).erase(test.at(i).begin());
  //   }
  //   std::cout << std::endl;
  // }

  // for (auto &pair : data) {
  //   for (int i = 0; i < 3; i++) {
  //     std::cout << pair.second.at(i);
  //     pair.second.erase(pair.second.begin());
  //   }
  //   std::cout << std::endl;
  // }
}

// void Pixelization::generateFinalFile(std::map<int, std::vector<double>> map)
// {
//   std::ofstream final("final_file.csv");
//   std::map<int, std::vector<double>>::iterator itr = map.begin();
//
//   for (int i = 0; i < bf->getMaxI(); i++) {
//   }
// }

// void Pixelization::setCurve(std::string curve) {
//   if (curve.compare("snakecurve") == 0) {
//     this->curve = SnakeCurve{bf->getNumOfModels()};
//   }
// }
