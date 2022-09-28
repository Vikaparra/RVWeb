import re
from Strategy import Strategy
from Property import Property
from WellList import WellList


class Configuration:
    def __init__(self, configs):
        self.root = configs[1]
        self.benchmark = configs[2]
        self.folder2d = configs[3]
        self.folderDistMatr = configs[4]
        self.chartType = configs[5]
        self.layoutCurve = configs[6]
        clustMethod = configs[7]
        distMatrix = configs[8]
        minClusters = int(configs[9])
        maxClusters = int(configs[10])
        numIterations = int(configs[11])
        self.allModels = configs[14]
        self.hlModels = configs[15]
        self.strategies = []
        self.properties = []

        regexFirst(self, configs[12], "Property")
        regexFirst(self, configs[13], "Strategy")


def getStrategies(self):
    for strat in self.strategies:
        print("Estrategia: "+strat.getStrategy())


def getProperties(self):
    for prop in self.properties:
        print("Propriedade: "+prop.getProperty())


def regexFirst(self, strats, type):
    stringStrats = strats
    arrayStrats = []
    regex = "(?<=\')[^',]+(?=\')"

    arrayStrats = eval(f"[{stringStrats}]")

    for strat in arrayStrats:
        regexSecond(self, strat, type)


def regexSecond(self, strats, type):
    stringStrats = strats
    regex = "[^;]+"
    arrayStrats = []

    arrayStrats = stringStrats.split(";")

    if (type == "Property"):
        property = Property(arrayStrats)
        self.properties.append(property)
    elif (type == "Strategy"):
        strategy = Strategy(arrayStrats)
        self.strategies.append(strategy)
        getStrategies(self)


def createWellList(self):
    estrategias = []

    if (~(self.strategies.empty())):
        for strategy in self.strategies:
            name = strategy.getName()
            path = strategy.getPath()
            wellList = WellList(name)
            estrategias.push_back(wellList)
            estrategias[i].loadFile(path)

    return estrategias

# TODO LEMBRAR DE MUDAR NOME (PENSAR EM UM NOME DECENTE)
def settingDrawConfigs(self, estrategias):
    for p in self.properties:
        distMatrixFileName = self.clusteringConfig.getDistMatrix()
        meanType = p.convertMeanType()
        # TODO this.loadStaticMapModels(propName, self.root/self.file2d/self.getNullBlocks, meanType)
        if (distMatrixFileName == "MODELS3D_ALL_PROP" | distMatrixFileName == "MODELS3D_PROP"):

            # TODO FAZER FILE WRITER
            distMatrixPath = self.root + "/" + self.folderDistMatr + "/" + distMatrixFileName

            # TODO Clustering clusteringData = self.clusterConfig.clusterReservoirsMatrixFile(distMatrixPath, false)
            # TODO self.clusterConfig.reorderReservoirByClusters(clusteringData)

        elif (distMatrixFileName == "FEATVECTORS_PROP" ):

            # TODO FAZER FILE WRITER

            # TODO featureVecFile = self.clusteringConfig.createReservoirFeatureVecMatrix()
            # TODO Clustering clusteringData = self.clusterConfig.clusterReservoirsFeatMatrix(featureVecFile)
            # TODO self.clusterConfig.reorderReservoirByClusters(clusteringData)

            chartType = self.layoutCurve

        if(chartType == "pixelization"):
            print('pixelization')
        elif (chartType == "smallmultiples"):
            print('small multiples')
        else:
            print('Tipo de desenho não reconhecido, favor escolher entre pixelization e small multiples')
            # TODO  FAZER ILLEGAL EXCEPTION
