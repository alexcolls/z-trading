

AssetList = [ "A", "B", "C", "D" , "E", "F", "G", "J", "H", "I" ]

ASS = 10
APA = 5

alg = 0
def setSymsPerAlgo( assetlist, recarr, i, ass, apa ):
    global alg
    if apa == 0:
        idx = []
        for sym in recarr:
            ix = AssetList.index(sym)
            idx.append(ix)
        print(alg)
        print(recarr)
        print(idx)
        alg += 1
        return
    for j in range(i,ass):
        aux = []
        aux.extend(recarr)
        aux.extend(assetlist[j])
        setSymsPerAlgo(assetlist, aux, j+1, ass, apa -1)

setSymsPerAlgo(AssetList,[],0,ASS,APA)