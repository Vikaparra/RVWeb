#include "Metadata.hpp"

#include "IJKKey.hpp"
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <search.h>
#include <stdlib.h>
#include <vector>

class FeatureVector {
private:
  Metadata *md = md->getInstance();
  size_t sizeI = md->getMaxI();
  size_t sizeJ = md->getMaxJ();
  int te = 10;
  std::map<IJKKey, int> map;

  int *iFeatureVectorLevel1 = new int[sizeI]{0};
  int *iFeatureVectorLevel2 = new int[sizeI]{0};
  int *iFeatureVectorLevel3 = new int[sizeI]{0};

  int *jFeatureVectorLevel1 = new int[sizeJ]{0};
  int *jFeatureVectorLevel2 = new int[sizeJ]{0};
  int *jFeatureVectorLevel3 = new int[sizeJ]{0};

public:
  // TODO: Check if there is already a solution for this. An attempt to
  //  recreate Java getOrDefault method for map.
  double getOrDefault(IJKKey key, double def) {
    return this->map.count(key) == 0 ? def : this->map[key];
  }

  double getValue(int i, int j, int k, std::string property) {
    return this->getOrDefault(IJKKey(property, i, j, k), 0);
  }

  double getPercentile(std::string property, double percentile) {
    std::vector<double> data;
    std::map<IJKKey, int>::iterator it = this->map.begin();
    while (it != this->map.end()) {
      if (it->first.getProperty().compare(property) == 0) {
        if (it->second == std::numeric_limits<double>::quiet_NaN()) {
          data.push_back(it->second);
        }
      }
    }
    sort(data.begin(), data.end());
    return data.at(static_cast<int>(data.size() * percentile));
  }

  std::vector<int> getFeatureVector(int index, std::string property) {
    // Filling the vector with zeros
    std::fill(this->iFeatureVectorLevel1, this->iFeatureVectorLevel1 + sizeI,
              0);
    std::fill(this->iFeatureVectorLevel2, this->iFeatureVectorLevel2 + sizeI,
              0);
    std::fill(this->iFeatureVectorLevel3, this->iFeatureVectorLevel3 + sizeI,
              0);

    std::fill(this->jFeatureVectorLevel1, this->jFeatureVectorLevel1 + sizeJ,
              0);
    std::fill(this->jFeatureVectorLevel2, this->jFeatureVectorLevel2 + sizeJ,
              0);
    std::fill(this->jFeatureVectorLevel3, this->jFeatureVectorLevel3 + sizeJ,
              0);

    double thresholdOne = this->getPercentile(property, 0.33);
    double thresholdTwo = this->getPercentile(property, 0.67);

    std::vector<int> featureVector;

    for (int i = 0; i < sizeI; i++) {
      for (int j = 0; j < sizeJ; j++) {
        double value = this->getValue(i + 1, j + 1, index, property);
        if (value < thresholdOne) {
          iFeatureVectorLevel1++;
          jFeatureVectorLevel1++;
        } else if (value < thresholdTwo) {

          iFeatureVectorLevel2++;
          jFeatureVectorLevel2++;
        } else {

          iFeatureVectorLevel3++;
          jFeatureVectorLevel3++;
        }
      }
    }

    // Copying the array's content to feature vector
    std::copy(this->iFeatureVectorLevel1, this->iFeatureVectorLevel1 + sizeI,
              back_inserter(featureVector));
    std::copy(this->iFeatureVectorLevel2, this->iFeatureVectorLevel2 + sizeI,
              back_inserter(featureVector));
    std::copy(this->iFeatureVectorLevel3, this->iFeatureVectorLevel3 + sizeI,
              back_inserter(featureVector));

    std::copy(this->jFeatureVectorLevel1, this->jFeatureVectorLevel1 + sizeJ,
              back_inserter(featureVector));
    std::copy(this->jFeatureVectorLevel2, this->jFeatureVectorLevel2 + sizeJ,
              back_inserter(featureVector));
    std::copy(this->jFeatureVectorLevel3, this->jFeatureVectorLevel3 + sizeJ,
              back_inserter(featureVector));

    return featureVector;
  }
};
