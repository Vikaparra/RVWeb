#include "RVConfig.hpp"

Configuration::Configuration(char **configs)
{
    this->root = configs[1];
    this->benchmark = configs[2];
    this->folder2d = configs[3];
    this->folderDistMatr = configs[4];
    this->chartType = configs[5];
    this->layoutCurve = configs[6];
    string clustMethod = configs[7];
    string distMatrix = configs[8];
    int minClusters = stoi(configs[9]);
    int maxClusters = stoi(configs[10]);
    int numIterations = stoi(configs[11]);
    this->allModels = configs[14];
    this->hlModels = configs[15];

    this->clusteringConfig(clustMethod, distMatrix, minClusters, maxClusters, numIterations);

    this->regexFirst(configs[12], "Property");
    this->regexFirst(configs[13], "Strategy");
};

void Configuration::regexFirst(char *strats, string type)
{

    string stringStrats(strats);

    boost::regex regex("(?<=\')[^',]+(?=\')");

    boost::sregex_token_iterator iter(stringStrats.begin(), stringStrats.end(), regex, 0);
    boost::sregex_token_iterator end;

    std::vector<std::string> stratsSplit(iter, end);

    for (const auto &s : stratsSplit)
    {
        regexSecond(s, type);
    }
}

void Configuration::regexSecond(string strats, string type)
{
    boost::regex regex("[^;]+");

    boost::sregex_token_iterator iter(strats.begin(), strats.end(), regex, 0);
    boost::sregex_token_iterator end;

    vector<string> sSplit(iter, end);

    if (type == "Strategy")
    {
        Strategy strategy(sSplit);
        this->strategies.push_back(strategy);
    }
    else if (type == "Property")
    {
        Property property(sSplit);
        this->properties.push_back(property);
    }
}

vector<WellList> Configuration::createWellList()
{
    vector<WellList> estrategias;

    if (!(this->strategies.empty()))
    {
        for (int i; i < this->strategies.size(); i++)
        {
            string name = this->strategies[i].getName();
            string path = this->strategies[i].getPath();
            WellList wellList(name);
            estrategias.push_back(wellList);
            estrategias[i].loadFile(path);
        }
    }
}

// LEMBRAR DE MUDAR NOME (PENSAR EM UM NOME DECENTE)
void Configuration::createEverythingTheUltimateGodFunction(vector<WellList> estrategias)
{
    for (auto &p : this->properties)
    {
        int meanType = p.convertMeanType();
        // this.loadStaticMapModels(propName, this->root/this->file2d/this->getNullBlocks, meanType);
        if (this->clusteringConfig->distMatrix == "MODELS3D_ALL_PROP" || this->clusteringConfig->distMatrix == "MODELS3D_PROP")
        {

            // FAZER FILE WRITER

            string distMatrixFileName = this->clusteringConfig->getDistMatrix();
            string distMatrixPath = this->root + "/" + this->folderDistMatr + "/" + distMatrixFileName;

            //clusteringData = this->clusterConfig.clusterReservoirsMatrixFile(distMatrixPath, false);
            //this->clusterConfig.reorderReservoirByClusters(clusteringData)
            
            

        }
    }
}
