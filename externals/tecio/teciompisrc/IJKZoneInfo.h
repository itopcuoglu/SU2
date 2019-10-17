 #pragma once
#include "ThirdPartyHeadersBegin.h"
#include <vector>
#include <boost/unordered_map.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "SzlFileLoader.h"
#include "IJKSubzoneInfo.h"
#include "MinMax.h"
namespace tecplot { namespace ___3933 { class ___1881 { public: typedef boost::unordered_map<___2090::SubzoneOffset_t, std::vector<___2479> > NszMinMaxMap; static const ___1844 ijkCornerOffset[NUM_IJK_CELL_CORNERS]; static const ___1844 ijkFaceNeighborOffset[NUM_IJK_CELL_FACES]; private: IJKSubzoneInfo m_cszInfo; IJKSubzoneInfo m_nszInfo;
 #if !defined NO_ASSERTS
___2090::___2980 m_partition;
 #endif
bool m_includeIMaxNodesInSubzones; bool m_includeJMaxNodesInSubzones; bool m_includeKMaxNodesInSubzones; NszMinMaxMap m_nszMinMaxes; public: ___1881( ___1844 const& ___2714, ___1844 const& subzoneMaxIJKDim, ___2090::___2980 ___2977 = ___2090::UNKNOWN_PARTITION, bool minimizeNumSubzones = DEFAULT_MINIMIZE_IJK_NUM_SUBZONES, bool includeIMaxNodesInSubzones = true, bool includeJMaxNodesInSubzones = true, bool includeKMaxNodesInSubzones = true) : m_cszInfo( ___2714.getCellIJK(), subzoneMaxIJKDim, ___2977, minimizeNumSubzones ) , m_nszInfo(___1844(includeIMaxNodesInSubzones ? ___2714.i() : ___2714.i() - 1, includeJMaxNodesInSubzones ? ___2714.___2105() : ___2714.___2105() - 1, includeKMaxNodesInSubzones ? ___2714.___2134() : ___2714.___2134() - 1), subzoneMaxIJKDim, ___2977, minimizeNumSubzones)
 #if !defined NO_ASSERTS
, m_partition(___2977)
 #endif
, m_includeIMaxNodesInSubzones(includeIMaxNodesInSubzones) , m_includeJMaxNodesInSubzones(includeJMaxNodesInSubzones) , m_includeKMaxNodesInSubzones(includeKMaxNodesInSubzones) { ___4278(___2977); REQUIRE(___2714>0); REQUIRE(subzoneMaxIJKDim>0); } ___1881() {} ___1881( ___2090::___2980 ___2977, IJKSubzoneInfo const& nodeSubzoneInfo, IJKSubzoneInfo const& cellSubzoneInfo) : m_cszInfo(cellSubzoneInfo) , m_nszInfo(nodeSubzoneInfo)
 #if !defined NO_ASSERTS
, m_partition(___2977)
 #endif
, m_includeIMaxNodesInSubzones(true) , m_includeJMaxNodesInSubzones(true) , m_includeKMaxNodesInSubzones(true) { ___4278(___2977); REQUIRE(___2977 >= 0); } ~___1881() {} inline void swap(___1881& ___2888) { m_cszInfo.swap(___2888.m_cszInfo); m_nszInfo.swap(___2888.m_nszInfo); } inline void reset( ___1844 const& ___2714, ___1844 const& subzoneMaxIJKDim, bool minimizeNumSubzones = DEFAULT_MINIMIZE_IJK_NUM_SUBZONES, bool includeIMaxNodesInSubzones = true, bool includeJMaxNodesInSubzones = true, bool includeKMaxNodesInSubzones = true) { REQUIRE(___2714>0); REQUIRE(subzoneMaxIJKDim>0); m_cszInfo.reset( ___2714.getCellIJK(), subzoneMaxIJKDim, minimizeNumSubzones ); m_nszInfo.reset( ___2714, subzoneMaxIJKDim, minimizeNumSubzones ); m_includeIMaxNodesInSubzones = includeIMaxNodesInSubzones; m_includeJMaxNodesInSubzones = includeJMaxNodesInSubzones; m_includeKMaxNodesInSubzones = includeKMaxNodesInSubzones; } inline bool ___2067() const { return m_cszInfo.___2067() && m_nszInfo.___2067(); } inline bool validCszAddress(___2090::SubzoneAddress cszAddress) const { return m_cszInfo.validSzAddress(cszAddress); } inline bool validNszAddress(___2090::SubzoneAddress nszAddress) const { return m_nszInfo.validSzAddress(nszAddress); } inline bool validCellSubzone(___2090::SubzoneOffset_t ___469) const { return m_cszInfo.validSubzone(___469); } inline bool validNodeSubzone(___2090::SubzoneOffset_t ___2734) const { return m_nszInfo.validSubzone(___2734); } inline bool validCellAddress(___2090 ___451) const { return validCszAddress(___451.subzoneAddress()) && ___451.itemOffset() < getNumCellsInCsz(___451.subzoneOffset()); } inline bool validNodeAddress(___2090 nodeAddress) const { return validNszAddress(nodeAddress.subzoneAddress()) && nodeAddress.itemOffset() < getNumNodesInNsz(nodeAddress.subzoneOffset()); } bool includeIMaxNodesInSubzones() const { return m_includeIMaxNodesInSubzones; } bool includeJMaxNodesInSubzones() const { return m_includeJMaxNodesInSubzones; } bool includeKMaxNodesInSubzones() const { return m_includeKMaxNodesInSubzones; } inline ___465 ___1766(void) const { return ___465(m_cszInfo.getNumItems()); } inline ___2718 ___1768(void) const { return ___2718(m_nszInfo.getNumItems()); } inline ___1844 const ___2895() const { return ___1844(m_cszInfo.ijkDim().i() + 1, m_cszInfo.ijkDim().___2105() + 1, m_cszInfo.ijkDim().___2134()); } inline ___1844 const& contiguousCellIJKDim() const { return m_cszInfo.ijkDim(); } inline ___1844 const& ___2714() const { return m_nszInfo.ijkDim(); } inline ___1844 const& ___2198() const { return m_cszInfo.ijkLastIndex(); } inline ___1844 const& ___2199() const { return m_nszInfo.ijkLastIndex(); } inline ___1844 ___690(___2090::SubzoneOffset_t ___469) const { REQUIRE(___469 < getNumCszs()); return m_cszInfo.subzoneIJKStart(___469); } inline ___1844 ___689(___2090::SubzoneOffset_t ___469) const { REQUIRE(___469 < getNumCszs());
return m_cszInfo.subzoneIJKEnd(___469); } inline ___1844 ___2761(___2090::SubzoneOffset_t ___2734) const { REQUIRE(___2734 < getNumNszs()); return m_nszInfo.subzoneIJKStart(___2734); } inline ___1844 ___2760(___2090::SubzoneOffset_t ___2734) const { REQUIRE(___2734 < getNumNszs()); return m_nszInfo.subzoneIJKEnd(___2734); } inline void nszIJKStartAndEnd( ___2090::SubzoneOffset_t ___2734, ___1844& ___1880, ___1844& ___1852) const { REQUIRE(___2734 < getNumNszs()); m_nszInfo.subzoneIJKStartAndEnd(___2734, ___1880, ___1852); } static ___2090::SubzoneOffset_t calcNumCszs( ___1844 const& zoneIJKDim, ___1844 const& subzoneMaxIJK, bool minimizeNumSubzones = DEFAULT_MINIMIZE_IJK_NUM_SUBZONES) { REQUIRE(zoneIJKDim>0 && zoneIJKDim.getNumPaddedCells()<=MAX_NUM_CELLS); REQUIRE(subzoneMaxIJK>0 && subzoneMaxIJK.blockSize()<=___2090::MAX_ITEM_OFFSET+1); ___2090::SubzoneOffset_t const ___2783 = IJKSubzoneInfo::calcNumSubzones(zoneIJKDim.getCellIJK(), subzoneMaxIJK, minimizeNumSubzones); ENSURE(___2783>0 && ___2783 <= zoneIJKDim.getNumContiguousCells()); return ___2783; } static ___2090::SubzoneOffset_t calcNumNszs( ___1844 const& zoneIJKDim, ___1844 const& subzoneMaxIJK, bool minimizeNumSubzones = DEFAULT_MINIMIZE_IJK_NUM_SUBZONES) { REQUIRE(zoneIJKDim>0 && zoneIJKDim.blockSize()<=MAX_NUM_NODES); REQUIRE(subzoneMaxIJK>0 && subzoneMaxIJK.blockSize()<=___2090::MAX_ITEM_OFFSET+1); ___2090::SubzoneOffset_t const ___2823 = IJKSubzoneInfo::calcNumSubzones(zoneIJKDim, subzoneMaxIJK, minimizeNumSubzones); ENSURE(___2823>0 && ___2823 <= zoneIJKDim.blockSize()); return ___2823; } inline ___2090::SubzoneOffset_t getNumCszs(void) const { return m_cszInfo.getNumSzs(); } inline ___2090::ItemOffset_t getNumCellsInCsz(___2090::SubzoneOffset_t ___469) const { REQUIRE(validCellSubzone(___469)); ___2090::ItemOffset_t const ___2781 = m_cszInfo.numItemsInSz(___469); ENSURE(0 < ___2781 && ___2781 < ___2090::MAX_ITEM_OFFSET+1); return ___2781; } inline ___2090 cellAddressAtCellIJK(___1844 const& cellIJK) const { REQUIRE(cellIJK < m_cszInfo.ijkDim()); ___2090 const ___451 = m_cszInfo.itemAddressAtItemIJK(cellIJK); ENSURE(validCellAddress(___451)); return ___451; } inline ___1844 cellIJKAtCellAddress(___2090 ___451) const { REQUIRE(validCellAddress(___451)); ___1844 const cellIJK = m_cszInfo.itemIJKAtItemAddress(___451); ENSURE(cellIJK < m_cszInfo.ijkDim()); return cellIJK; } inline ___2090 cellAddressAtContiguousCellIndex(___465 contiguousCellIndex) const { REQUIRE(contiguousCellIndex < ___1766()); ___2090 const ___451 = m_cszInfo.itemAddressAtItemIndex(contiguousCellIndex); ENSURE(validCellAddress(___451)); return ___451; } inline ___465 contiguousCellIndexAtCellAddress(___2090 ___451) const { REQUIRE(validCellAddress(___451)); ___465 const contiguousCellIndex = m_cszInfo.itemIndexAtItemAddress(___451);
ENSURE(contiguousCellIndex<___1766()); return contiguousCellIndex; } inline ___465 contiguousCellIndexAtCellIJK(___1844 const& cellIJK) const { ___465 const contiguousCellIndex = m_cszInfo.itemIndexAtItemIJK(cellIJK); ENSURE(contiguousCellIndex<___1766()); return contiguousCellIndex; } inline ___465 getMaxPaddedCellIndex() const { REQUIRE(m_includeIMaxNodesInSubzones && m_includeJMaxNodesInSubzones && m_includeKMaxNodesInSubzones); return m_nszInfo.ijkDim().i() * m_nszInfo.ijkDim().___2105() * m_cszInfo.ijkDim().___2134(); } inline ___2090 cellAddressAtPaddedCellIndex(___465 paddedCellIndex) const { REQUIRE(paddedCellIndex < getMaxPaddedCellIndex()); REQUIRE(m_includeIMaxNodesInSubzones && m_includeJMaxNodesInSubzones && m_includeKMaxNodesInSubzones); ___1844 cellIJK = m_nszInfo.itemIJKAtItemIndex(paddedCellIndex); if ( cellIJK.i() == m_cszInfo.ijkDim().i() ) cellIJK.setI(m_cszInfo.ijkLastIndex().i()); if ( cellIJK.___2105() == m_cszInfo.ijkDim().___2105() ) cellIJK.setJ(m_cszInfo.ijkLastIndex().___2105()); REQUIRE(cellIJK<m_cszInfo.ijkDim()); ___2090 const ___451 = m_cszInfo.itemAddressAtItemIJK(cellIJK); ENSURE(validCellAddress(___451)); return ___451; } inline ___465 paddedCellIndexAtCellAddress(___2090 ___451) const { REQUIRE(validCellAddress(___451)); ___1844 const cellIJK = m_cszInfo.itemIJKAtItemAddress(___451); ___465 const paddedCellIndex = paddedCellIndexAtCellIJK(cellIJK); ENSURE(paddedCellIndex < getMaxPaddedCellIndex()); return paddedCellIndex; } inline ___465 paddedCellIndexAtCellIJK(___1844 const& cellIJK) const { REQUIRE(m_includeIMaxNodesInSubzones && m_includeJMaxNodesInSubzones && m_includeKMaxNodesInSubzones); ___465 const paddedCellIndex = m_nszInfo.itemIndexAtItemIJK(cellIJK); ENSURE(paddedCellIndex < getMaxPaddedCellIndex()); return paddedCellIndex; } inline ___2090::SubzoneAddress cszAtCellIJK(___1844 const& cellIJK) const { REQUIRE(cellIJK < m_cszInfo.ijkDim()); ___2090::SubzoneAddress const cszAddress = m_cszInfo.szAddressAtItemIJK(cellIJK); ENSURE(validCszAddress(cszAddress)); return cszAddress; } inline ___2090::SubzoneOffset_t getNumNszs(void) const { return m_nszInfo.getNumSzs(); } inline ___2090::ItemOffset_t getNumNodesInNsz(___2090::SubzoneOffset_t ___2734) const { REQUIRE(validNodeSubzone(___2734)); ___2090::ItemOffset_t const ___2821 = m_nszInfo.numItemsInSz(___2734); ENSURE(0 < ___2821 && ___2821 < ___2090::MAX_ITEM_OFFSET+1); return ___2821; } inline ___2090 nodeAddressAtNodeIJK(___1844 const& nodeIJK) const { REQUIRE(nodeIJK < m_nszInfo.ijkDim()); ___2090 const nodeAddress = m_nszInfo.itemAddressAtItemIJK(nodeIJK); ENSURE(validNodeAddress(nodeAddress)); return nodeAddress; } inline ___1844 nodeIJKAtNodeAddress(___2090 nodeAddress) const { REQUIRE(validNodeAddress(nodeAddress)); ___1844 const nodeIJK = m_nszInfo.itemIJKAtItemAddress(nodeAddress); ENSURE(nodeIJK < m_nszInfo.ijkDim()); return nodeIJK; } inline ___2090 nodeAddressAtNodeIndex(___2718 ___2716) const
{ REQUIRE(___2716 < ___1768()); ___2090 const nodeAddress = m_nszInfo.itemAddressAtItemIndex(___2716); return nodeAddress; } inline ___2090::SubzoneAddress nszAtNodeIJK(___1844 const& nodeIJK) const { REQUIRE(nodeIJK < m_nszInfo.ijkDim()); ___2090::SubzoneAddress const nszAddress = m_nszInfo.szAddressAtItemIJK(nodeIJK); ENSURE(validNszAddress(nszAddress)); return nszAddress; } inline ___2718 nodeIndexAtNodeAddress(___2090 nodeAddress) const { REQUIRE(validNodeAddress(nodeAddress)); ___2718 const ___2716 = m_nszInfo.itemIndexAtItemAddress(nodeAddress); ENSURE(___2716<___1768()); return ___2716; } inline ___2718 nodeIndexAtNodeIJK(___1844 const& nodeIJK) const { ___2718 const ___2716 = m_nszInfo.itemIndexAtItemIJK(nodeIJK); ENSURE(___2716<___1768()); return ___2716; } inline ___2090 getCellCorner( ___2090   ___451, ___682 ___681) const { REQUIRE(validCellAddress(___451)); REQUIRE(___681 < NUM_IJK_CELL_CORNERS); ___1844 const zoneCellIJK = m_cszInfo.itemIJKAtItemAddress(___451); ___1844 const cornerIJK = zoneCellIJK + ijkCornerOffset[___681]; ___478(0 <= cornerIJK); ___2090 cornerNodeAddress; if (cornerIJK < ___2714()) { cornerNodeAddress = nodeAddressAtNodeIJK(cornerIJK); ___478(validNodeAddress(cornerNodeAddress)); } else { cornerNodeAddress = ___2090(BAD_ANY_INDEX); } return cornerNodeAddress; } inline void getCellCorners( ___2090            ___451, ___3269<___2090>& cornerNodeAddresses) const { REQUIRE(validCellAddress(___451)); REQUIRE(cornerNodeAddresses.empty()); cornerNodeAddresses.reserve(NUM_IJK_CELL_CORNERS); cornerNodeAddresses.___3503(NUM_IJK_CELL_CORNERS); ___1844 const zoneCellIJK = m_cszInfo.itemIJKAtItemAddress(___451); ___1844 const& nodeSzIJKDim = ___2714(); ___1844 const baseSzIJK = m_nszInfo.szIJKAtItemIJK(zoneCellIJK); ___1844 const baseIJKEnd = m_nszInfo.itemIJKEnd(baseSzIJK); for (___682 ___681 = 0; ___681 < NUM_IJK_CELL_CORNERS; ++___681) { ___1844 const cornerIJK = zoneCellIJK + ijkCornerOffset[___681]; ___478(0 <= cornerIJK); if (cornerIJK < nodeSzIJKDim) { ___1844 const nszIJK(cornerIJK.i() > baseIJKEnd.i() ? baseSzIJK.i()+1 : baseSzIJK.i(), cornerIJK.___2105() > baseIJKEnd.___2105() ? baseSzIJK.___2105()+1 : baseSzIJK.___2105(), cornerIJK.___2134() > baseIJKEnd.___2134() ? baseSzIJK.___2134()+1 : baseSzIJK.___2134()); cornerNodeAddresses[___681] = m_nszInfo.itemAddressAtItemIJK(cornerIJK, nszIJK); ___478(validNodeAddress(cornerNodeAddresses[___681])); } else { cornerNodeAddresses[___681] = ___2090(BAD_ANY_INDEX); } } } inline ___465 getNumIJKFaceNeighbors( ___2090 ___451, FaceIndex_t ASSERT_ONLY(___457)) const { ___4278(___451); REQUIRE(___457 < NUM_IJK_CELL_FACES); return 1; } inline void cszFaceNeighborIJKRange( ___2090::SubzoneOffset_t ___469, int                          iDir, int                          jDir, int                          kDir, ___2090::SubzoneAddress& fnCszAddress, ___1844&                         fnCszIJKRange) const { REQUIRE(validCellSubzone(___469));
REQUIRE(iDir == -1 || iDir == 0 || iDir == 1); REQUIRE(jDir == -1 || jDir == 0 || jDir == 1); REQUIRE(kDir == -1 || kDir == 0 || kDir == 1); REQUIRE((iDir != 0 && jDir == 0 && kDir == 0) || (iDir == 0 && jDir != 0 && kDir == 0) || (iDir == 0 && jDir == 0 && kDir != 0)); ___1844 const subzoneIJK = m_cszInfo.szIJKAtSzIndex(___469); fnCszAddress = m_cszInfo.szAddressAtSzIJK( ___1844(subzoneIJK.i()+iDir,subzoneIJK.___2105()+jDir,subzoneIJK.___2134()+kDir)); ___1844 const fnCszIJKStart = m_cszInfo.subzoneIJKStart(fnCszAddress.subzoneOffset()); ___1844 const fnCszIJKEnd = m_cszInfo.subzoneIJKEnd(fnCszAddress.subzoneOffset()); fnCszIJKRange = fnCszIJKEnd-fnCszIJKStart+1; } inline void getIJKFaceNeighbor( ___2090  ___451, FaceIndex_t  ___457, ___465  ASSERT_ONLY(neighborOffset), ___2090& fnCoord, ___4636& fnZone) const { REQUIRE(___457 < NUM_IJK_CELL_FACES); REQUIRE(neighborOffset < getNumIJKFaceNeighbors(___451, ___457)); ___2090::SubzoneOffset_t const ___469 = ___451.subzoneOffset(); ___2090::ItemOffset_t const ___2865 = ___451.itemOffset(); ___1844 const ijkLastIndex = m_cszInfo.ijkLastIndex(); ___1844 const ___1880 = m_cszInfo.subzoneIJKStart(___469); ___1844 const ___1852 = m_cszInfo.subzoneIJKEnd(___469); ___1844 const ijkRange = ___1852-___1880+1; ___1844 const ___1862 = ijkRange.ijkAtOffset(___2865); ___1844 const ijkCell = ___1880 + ___1862; ___2090::SubzoneAddress fnCszAddress; ___1844 fnCszIJKRange; switch (___457) { case 0: if (ijkCell.i() > 0) { if (___1862.i() > 0) { fnCoord = m_cszInfo.itemAddressAtItemIJK(ijkCell - ___1844(1,0,0)); } else { cszFaceNeighborIJKRange(___469, -1, 0, 0, fnCszAddress, fnCszIJKRange); ___1844 const fnCszIJKOffset(fnCszIJKRange.i()-1,___1862.___2105(),___1862.___2134()); fnCoord = ___2090( fnCszAddress, static_cast<___2090::ItemOffset_t>(fnCszIJKRange.offsetAtIJK(fnCszIJKOffset))); } } else { fnCoord = ___2090(___2749); } break; case 1: if (ijkCell.i() < ijkLastIndex.i()) { if (___1862.i() < ijkRange.i()-1) { fnCoord = m_cszInfo.itemAddressAtItemIJK(ijkCell + ___1844(1,0,0)); } else { cszFaceNeighborIJKRange(___469, 1,0,0, fnCszAddress, fnCszIJKRange); ___1844 const fnCszIJKOffset(0,___1862.___2105(),___1862.___2134()); fnCoord = ___2090( fnCszAddress,static_cast<___2090::ItemOffset_t>(fnCszIJKRange.offsetAtIJK(fnCszIJKOffset))); } } else { fnCoord = ___2090(___2749); } break; case 2: if (ijkCell.___2105() > 0) { if (___1862.___2105() > 0) { fnCoord = m_cszInfo.itemAddressAtItemIJK(ijkCell - ___1844(0,1,0)); } else { cszFaceNeighborIJKRange(___469, 0, -1, 0, fnCszAddress, fnCszIJKRange); ___1844 const fnCszIJKOffset(___1862.i(),fnCszIJKRange.___2105()-1,___1862.___2134()); fnCoord = ___2090( fnCszAddress,static_cast<___2090::ItemOffset_t>(fnCszIJKRange.offsetAtIJK(fnCszIJKOffset))); } } else { fnCoord = ___2090(___2749); } break; case 3: if (ijkCell.___2105() < ijkLastIndex.___2105()) { if (___1862.___2105() < ijkRange.___2105()-1) { fnCoord = m_cszInfo.itemAddressAtItemIJK(ijkCell + ___1844(0,1,0));
} else { cszFaceNeighborIJKRange(___469, 0, 1, 0, fnCszAddress, fnCszIJKRange); ___1844 const fnCszIJKOffset(___1862.i(),0,___1862.___2134()); fnCoord = ___2090( fnCszAddress,static_cast<___2090::ItemOffset_t>(fnCszIJKRange.offsetAtIJK(fnCszIJKOffset))); } } else { fnCoord = ___2090(___2749); } break; case 4: if (ijkCell.___2134() > 0) { if (___1862.___2134() > 0) { fnCoord = m_cszInfo.itemAddressAtItemIJK(ijkCell - ___1844(0,0,1)); } else { cszFaceNeighborIJKRange(___469, 0, 0, -1, fnCszAddress, fnCszIJKRange); ___1844 const fnCszIJKOffset(___1862.i(),___1862.___2105(),fnCszIJKRange.___2134()-1); fnCoord = ___2090( fnCszAddress,static_cast<___2090::ItemOffset_t>(fnCszIJKRange.offsetAtIJK(fnCszIJKOffset))); } } else { fnCoord = ___2090(___2749); } break; case 5: if (ijkCell.___2134() < ijkLastIndex.___2134()) { if (___1862.___2134() < ijkRange.___2134()-1) { fnCoord = m_cszInfo.itemAddressAtItemIJK(ijkCell + ___1844(0,0,1)); } else { cszFaceNeighborIJKRange(___469, 0, 0, 1, fnCszAddress, fnCszIJKRange); ___1844 const fnCszIJKOffset(___1862.i(),___1862.___2105(),0); fnCoord = ___2090( fnCszAddress,static_cast<___2090::ItemOffset_t>(fnCszIJKRange.offsetAtIJK(fnCszIJKOffset))); } } else { fnCoord = ___2090(___2749); } break; default: ___478(___1305); break; } fnZone = ___2750; } ___465 getCellsAroundNodeIJK( ___1844 const&             nodeIJK, ___3269<___2090>& adjacentCells) const; ___372 getCszsOnIndexPlane( IJKPlanes_e                            whichPlane, ___2718                            planeIndex, ___3269<___2090::SubzoneAddress>& cszAddresses) const { REQUIRE(whichPlane == ___1867 || whichPlane == ___1872 || whichPlane == ___1874); REQUIRE(IMPLICATION(whichPlane == ___1867 ,planeIndex < m_nszInfo.ijkDim().i()) && IMPLICATION(whichPlane == ___1872 ,planeIndex < m_nszInfo.ijkDim().___2105()) && IMPLICATION(whichPlane == ___1874 ,planeIndex < m_nszInfo.ijkDim().___2134())); REQUIRE(cszAddresses.empty()); ___372 const ___2039 = m_cszInfo.getSubzonesOnIndexPlane(whichPlane, planeIndex, cszAddresses); ENSURE(IMPLICATION(___2039, !cszAddresses.empty())); ENSURE(IMPLICATION(___2039, isSorted(cszAddresses.begin(), cszAddresses.end()))); ENSURE(IMPLICATION(___2039, cszAddresses[cszAddresses.size()-1].___2977()==m_partition)); ENSURE(IMPLICATION(___2039, cszAddresses[cszAddresses.size()-1].subzoneOffset() < getNumCszs())); return ___2039; } ___372 getCszsOnIndexLine( IJKLines_e                             whichLine, ___2718                            mIndex, ___2718                            nIndex, ___3269<___2090::SubzoneAddress>& cszAddresses) const { REQUIRE(whichLine == ___1857 || whichLine == ___1859 || whichLine == ___1860); REQUIRE(IMPLICATION(whichLine == ___1857, mIndex < m_nszInfo.ijkDim().___2105() && nIndex < m_nszInfo.ijkDim().___2134()) && IMPLICATION(whichLine == ___1859, mIndex < m_nszInfo.ijkDim().i() && nIndex < m_nszInfo.ijkDim().___2134()) && IMPLICATION(whichLine == ___1860, mIndex < m_nszInfo.ijkDim().i() && nIndex < m_nszInfo.ijkDim().___2105()));
REQUIRE(cszAddresses.empty()); REQUIRE(m_includeIMaxNodesInSubzones && m_includeJMaxNodesInSubzones && m_includeKMaxNodesInSubzones); ___372 const ___2039 = m_cszInfo.getSubzonesOnIndexLine(whichLine, mIndex, nIndex, cszAddresses); ENSURE(IMPLICATION(___2039, !cszAddresses.empty())); ENSURE(IMPLICATION(___2039, isSorted(cszAddresses.begin(), cszAddresses.end()))); ENSURE(IMPLICATION(___2039, cszAddresses[cszAddresses.size()-1].___2977()==m_partition)); ENSURE(IMPLICATION(___2039, cszAddresses[cszAddresses.size()-1].subzoneOffset() < getNumCszs())); return ___2039; } ___372 getNszsOnIndexPlane( IJKPlanes_e                            whichPlane, ___2718                            planeIndex, ___3269<___2090::SubzoneAddress>& nszAddresses) const { REQUIRE(whichPlane == ___1867 || whichPlane == ___1872 || whichPlane == ___1874); REQUIRE(IMPLICATION(whichPlane == ___1867, planeIndex < m_nszInfo.ijkDim().i()) && IMPLICATION(whichPlane == ___1872, planeIndex < m_nszInfo.ijkDim().___2105()) && IMPLICATION(whichPlane == ___1874, planeIndex < m_nszInfo.ijkDim().___2134())); REQUIRE(nszAddresses.empty()); REQUIRE(m_includeIMaxNodesInSubzones && m_includeJMaxNodesInSubzones && m_includeKMaxNodesInSubzones); ___372 ___2039 = m_nszInfo.getSubzonesOnIndexPlane(whichPlane, planeIndex, nszAddresses); ENSURE(IMPLICATION(___2039, !nszAddresses.empty())); ENSURE(IMPLICATION(___2039, isSorted(nszAddresses.begin(), nszAddresses.end()))); ENSURE(IMPLICATION(___2039, nszAddresses[nszAddresses.size()-1].___2977()==m_partition)); ENSURE(IMPLICATION(___2039, nszAddresses[nszAddresses.size()-1].subzoneOffset() < getNumNszs())); return ___2039; } ___372 getNszsOnIndexLine( IJKLines_e                             whichLine, ___2718                            mIndex, ___2718                            nIndex, ___3269<___2090::SubzoneAddress>& nszAddresses) const { REQUIRE(whichLine == ___1857 || whichLine == ___1859 || whichLine == ___1860); REQUIRE(IMPLICATION(whichLine == ___1857, mIndex < m_nszInfo.ijkDim().___2105() && nIndex < m_nszInfo.ijkDim().___2134()) && IMPLICATION(whichLine == ___1859, mIndex < m_nszInfo.ijkDim().i() && nIndex < m_nszInfo.ijkDim().___2134()) && IMPLICATION(whichLine == ___1860, mIndex < m_nszInfo.ijkDim().i() && nIndex < m_nszInfo.ijkDim().___2105())); REQUIRE(nszAddresses.empty()); REQUIRE(m_includeIMaxNodesInSubzones && m_includeJMaxNodesInSubzones && m_includeKMaxNodesInSubzones); ___372 const ___2039 = m_nszInfo.getSubzonesOnIndexLine(whichLine, mIndex, nIndex, nszAddresses); ENSURE(IMPLICATION(___2039, !nszAddresses.empty())); ENSURE(IMPLICATION(___2039, isSorted(nszAddresses.begin(), nszAddresses.end()))); ENSURE(IMPLICATION(___2039, nszAddresses[nszAddresses.size()-1].___2977()==m_partition)); ENSURE(IMPLICATION(___2039, nszAddresses[nszAddresses.size()-1].subzoneOffset() < getNumNszs())); return ___2039; } void includeNszVarMinMax(___2090::SubzoneOffset_t ___2734, std::vector<___2479> const& varMinMaxes) { REQUIRE(!varMinMaxes.empty()); std::vector<___2479>& nszVarMinMaxes = m_nszMinMaxes[___2734];
if (nszVarMinMaxes.empty()) nszVarMinMaxes.resize(varMinMaxes.size()); for (size_t ___4336 = 0; ___4336 < varMinMaxes.size(); ++___4336) nszVarMinMaxes[___4336].include(varMinMaxes[___4336]); } NszMinMaxMap const& getNszMinMaxes() const { return m_nszMinMaxes; } inline void resetNeighborInfo() { m_nszMinMaxes.clear(); } ___372 getNodeSubzonesInRange( ___1844 const& nodeIJKStart, ___1844 const& nodeIJKEnd, ___3269<___2090::SubzoneAddress>& refNszAddresses) const; ___372 getCszReferencedNszs( ___2090::SubzoneAddress            cszAddress, ___3269<___2090::SubzoneAddress>& refNszAddresses) const; ___372 getCellSubzonesInRange( ___1844 const& cellIJKStart, ___1844 const& cellIJKEnd, ___3269<___2090::SubzoneAddress>& refCszAddresses) const; ___372 getNszReferencedCszs( ___2090::SubzoneAddress            nszAddress, ___3269<___2090::SubzoneAddress>& refCszAddresses) const; }; }}
