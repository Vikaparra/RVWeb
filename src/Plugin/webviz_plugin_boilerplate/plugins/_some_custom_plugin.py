from dash import html
import subprocess as sub
from webviz_config import WebvizPluginABC
import os
from RVConfig import Configuration


class SomeCustomPlugin(WebvizPluginABC):

    def __init__(self,
        root: str,
        benchmark: str,
        folder2d: str,
        folderDistMatr: str,
        chartType: str,
        layoutCurve: str,
        clusteringMethod: str,
        distanceMatrix: str,
        minClusters: str,
        maxClusters: str,
        iterations: str,
        properties: list,
        strategies: list,
        allModels: str,
    highlightedModels: str) -> None:

        super().__init__()

        self.root = root
        self.benchmark = benchmark
        self.folder2d = folder2d
        self.folderDistMatr = folderDistMatr
        self.chartType = chartType
        self.layoutCurve = layoutCurve
        self.clusteringMethod = clusteringMethod
        self.distanceMatrix = distanceMatrix
        self.minClusters = minClusters
        self.maxClusters = maxClusters
        self.iterations = iterations
        self.properties = properties
        self.strategies = strategies
        self.allModels = allModels
        self.highlightedModels = highlightedModels

        full_path = os.path.realpath(__file__)
        path = os.path.dirname(full_path) + "//..//..//..//..//Debug//RVWeb.exe"

        args = [
            path,
        self.root,
        self.benchmark,
        self.folder2d,
        self.folderDistMatr,
        self.chartType,
        self.layoutCurve,
        self.clusteringMethod,
        self.distanceMatrix,
        self.minClusters,
        self.maxClusters,
        self.iterations,
        str(self.properties),
        str(self.strategies),
        self.allModels,
        self.highlightedModels]

        #sub.run(args)

        rvConfig = Configuration(args)
        

    @property
    def layout(self):
        return (html.Div(
            [self.root,
        self.benchmark,
        self.folder2d,
        self.folderDistMatr,
        self.chartType,
        self.layoutCurve,
        self.clusteringMethod,
        self.distanceMatrix,
        self.minClusters,
        self.maxClusters,
        self.iterations,
        self.allModels,
        self.highlightedModels]
        ), html.Img('./assets/sapatinho.png')
)