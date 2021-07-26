#ifndef __C_NAVIGATION_MANAGER_H__
#define __C_NAVIGATION_MANAGER_H__

class cNavigationManager
{
public:
   cNavigationManager()
   {
      mMapFile = CreateFileMapping( INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof( sNavigationData ), "AFS_NAVIGATION_DATA" );
      mData = ( sNavigationData * ) MapViewOfFile( mMapFile, FILE_MAP_ALL_ACCESS, 0, 0, sizeof( sNavigationData ) );
   }

   ~cNavigationManager( void )
   {
      UnmapViewOfFile( mData );
      CloseHandle( mMapFile );
   }

   enum eFromTo
   {
      kFrom = 0,
      kTo
   };

   // VOR 
   //
   bool VorIlsValid() { return mData->mVorIls.isValid; }
   void VorIlsValid( bool valid ) { mData->mVorIls.isValid = valid; }

   bool IlsMode() { return mData->mVorIls.ilsMode; }
   void IlsMode( bool ilsMode ) { mData->mVorIls.ilsMode = ilsMode; }

   double VorIlsCourse( bool pilot = true ) { return ( pilot ) ? mData->mVorIls.coursePilot : mData->mVorIls.courseCopilot; }
   void VorIlsCourse( double course, bool pilot = true ) 
   {
      if ( pilot )
         mData->mVorIls.coursePilot = course;
      else
         mData->mVorIls.courseCopilot = course;
   }

   eFromTo VorIlsFromTo( bool pilot = true ) { return ( pilot ) ? mData->mVorIls.fromToPilot : mData->mVorIls.fromToCopilot; }
   void VorIlsFromTo( eFromTo fromTo, bool pilot = true )
   {
      if ( pilot )
         mData->mVorIls.fromToPilot = fromTo;
      else
         mData->mVorIls.fromToCopilot = fromTo;
   }

   double VorIlsBearing() { return mData->mVorIls.bearing; }
   void VorIlsBearing( double bearing ) { mData->mVorIls.bearing = bearing; }

   double VorIlsLatDeviation( bool pilot = true ) { return ( pilot ) ? mData->mVorIls.latDeviationPilot : mData->mVorIls.latDeviationCopilot; }
   void VorIlsLatDeviation( double latDeviation, bool pilot = true )
   {
      if ( pilot )
         mData->mVorIls.latDeviationPilot = latDeviation;
      else
         mData->mVorIls.latDeviationCopilot = latDeviation;
   }

   double VorIlsRange() { return mData->mVorIls.range; }
   void VorIlsRange( double range ) { mData->mVorIls.range = range; }

   double IlsGsRange() { return mData->mVorIls.gsRange; }
   void IlsGsRange( double range ) { mData->mVorIls.gsRange = range; }

   double IlsGsHeight() { return mData->mVorIls.gsHeight; }
   void IlsGsHeight( double range ) { mData->mVorIls.gsHeight = range; }

   double IlsVertDeviation() { return mData->mVorIls.verticalDeviation; }
   void IlsVertDeviation( double dev ) { mData->mVorIls.verticalDeviation = dev; }

   double VorIlsLatDevRateEst( bool pilot = true ) { return ( pilot ) ? mData->mVorIls.latDevRateEstPilot : mData->mVorIls.latDevRateEstCopilot; }
   void VorIlsLatDevRateEst( double rateEst, bool pilot = true )
   {
      if ( pilot )
         mData->mVorIls.latDevRateEstPilot = rateEst;
      else
         mData->mVorIls.latDevRateEstCopilot = rateEst;
   }

   // TACAN Mode
   //
   bool TacanValid() { return mData->mTacan.isValid; }
   void TacanValid( bool valid ) { mData->mTacan.isValid = valid; }

   double TacanCourse( bool pilot = true ) { return ( pilot ) ? mData->mTacan.coursePilot : mData->mTacan.courseCopilot; }
   void TacanCourse( double course, bool pilot = true ) 
   {
      if ( pilot )
         mData->mTacan.coursePilot = course;
      else
         mData->mTacan.courseCopilot = course;
   }

   eFromTo TacanFromTo( bool pilot = true ) { return ( pilot ) ? mData->mTacan.fromToPilot : mData->mTacan.fromToCopilot; }
   void TacanFromTo( eFromTo fromTo, bool pilot = true )
   {
      if ( pilot )
         mData->mTacan.fromToPilot = fromTo;
      else
         mData->mTacan.fromToCopilot = fromTo;
   }

   double TacanBearing() { return mData->mTacan.bearing; }
   void TacanBearing( double bearing ) { mData->mTacan.bearing = bearing; }

   double TacanLatDeviation( bool pilot = true ) { return ( pilot ) ? mData->mTacan.latDeviationPilot : mData->mTacan.latDeviationCopilot; }
   void TacanLatDeviation( double latDeviation, bool pilot = true )
   {
      if ( pilot )
         mData->mTacan.latDeviationPilot = latDeviation;
      else
         mData->mTacan.latDeviationCopilot = latDeviation;
   }

   double TacanRange() { return mData->mTacan.range; }
   void TacanRange( double range ) { mData->mTacan.range = range; }

   double TacanBearingRateEst( bool pilot = true ) { return ( pilot ) ? mData->mTacan.latDevRateEstPilot : mData->mTacan.latDevRateEstCopilot; }
   void TacanBearingRateEst( double rateEst, bool pilot = true )
   {
      if ( pilot )
         mData->mTacan.latDevRateEstPilot = rateEst;
      else
         mData->mTacan.latDevRateEstCopilot = rateEst;
   }

   // Flight Plan Mode
   //
   bool FlightPlanValid() { return mData->mFlightPlan.isValid; }
   void FlightPlanValid( bool valid ) { mData->mFlightPlan.isValid = valid; }

   eFromTo FlightPlanFromTo() { return mData->mFlightPlan.fromTo; }
   void FlightPlanFromTo( eFromTo fromTo ) { mData->mFlightPlan.fromTo = fromTo; }

   double FlightPlanCourse() { return mData->mFlightPlan.course; }
   void FlightPlanCourse( double crs ) { mData->mFlightPlan.course = crs; }

   double FlightPlanBearing() { return mData->mFlightPlan.bearing; }
   void FlightPlanBearing( double bearing ) { mData->mFlightPlan.bearing = bearing; }

   double FlightPlanLatDeviation() { return mData->mFlightPlan.latDeviation; }
   void FlightPlanLatDeviation( double latDeviation ) { mData->mFlightPlan.latDeviation = latDeviation; }

   double FlightPlanVertDeviation() { return mData->mFlightPlan.vertDeviation; }
   void FlightPlanVertDeviation( double vertDeviation ) { mData->mFlightPlan.vertDeviation = vertDeviation; }

   double FlightPlanRange() { return mData->mFlightPlan.range; }
   void FlightPlanRange( double range ) { mData->mFlightPlan.range = range; }

   double FlightPlanCrossTrackDistance() { return mData->mFlightPlan.crossTrackDistance; }
   void FlightPlanCrossTrackDistance( double crossTrackDistance ) { mData->mFlightPlan.crossTrackDistance = crossTrackDistance; }

   double FlightPlanCrossTrackAngle() { return mData->mFlightPlan.crossTrackAngle; }
   void FlightPlanCrossTrackAngle( double crossTrackAngle ) { mData->mFlightPlan.crossTrackAngle = crossTrackAngle; }

   int FlightPlanTimeToTurn() { return mData->mFlightPlan.timeToTurn; }
   void FlightPlanTimeToTurn( int secs ) { mData->mFlightPlan.timeToTurn = secs; }

   // Adf Data
   //
   bool AdfValid() { return mData->mAdf.isValid; }
   void AdfValid( bool valid ) { mData->mAdf.isValid = valid; }

   double AdfBearing() { return mData->mAdf.bearing; }
   void AdfBearing( double bearing ) { mData->mAdf.bearing = bearing; }

   double AdfRange() { return mData->mAdf.range; }
   void AdfRange( double range ) { mData->mAdf.range = range; }

   // Magnetic variation (declination)
   //
   double MagneticVariation() { return mData->mMagVar; }
   void MagneticVariation( double var ) { mData->mMagVar = var; }

   // Annunciators
   //
   bool IlsDecisionHeightAnnunciator() { return mData->mAnnunciators.ilsDecisionHeight; }
   void IlsDecisionHeightAnnunciator( bool val ) { mData->mAnnunciators.ilsDecisionHeight = val; }

   bool IlsMiddleMarkerAnnunciator() { return mData->mAnnunciators.ilsMiddleMarker; }
   void IlsMiddleMarkerAnnunciator( bool val ) { mData->mAnnunciators.ilsMiddleMarker = val; }

   bool IlsInnerMarkerAnnunciator() { return mData->mAnnunciators.ilsInnerMarker; }
   void IlsInnerMarkerAnnunciator( bool val ) { mData->mAnnunciators.ilsInnerMarker = val; }

   bool IlsOuterMarkerAnnunciator() { return mData->mAnnunciators.ilsOuterMarker; }
   void IlsOuterMarkerAnnunciator( bool val ) { mData->mAnnunciators.ilsOuterMarker = val; }

   bool IlsWithinConeAnnunciator() { return mData->mAnnunciators.ilsWithinCone; }
   void IlsWithinConeAnnunciator( bool val ) { mData->mAnnunciators.ilsWithinCone = val; }

   bool FlightPlanSeqFlashAnnunciator() { return mData->mAnnunciators.displayFlightPlanSeqFlash; }
   void FlightPlanSeqFlashAnnunciator( bool val ) { mData->mAnnunciators.displayFlightPlanSeqFlash = val; }
	
   bool FlightPlanVertFlashAnnunciator() { return mData->mAnnunciators.displayFlightPlanVertFlash; }
   void FlightPlanVertFlashAnnunciator( bool val ) { mData->mAnnunciators.displayFlightPlanVertFlash = val; }

   struct sNavigationData
   {
      struct sVorIls
      {
         bool isValid;
         bool ilsMode;
         eFromTo fromToPilot;
         eFromTo fromToCopilot;
         double coursePilot;
         double courseCopilot;
         double bearing;
         double latDeviationPilot;
         double latDeviationCopilot;
         double verticalDeviation;
         double range;
         double latDevRateEstPilot;
         double latDevRateEstCopilot;
         double gsHeight;
         double gsRange;
      } mVorIls;

      struct sTacan
      {
         bool isValid;
         eFromTo fromToPilot;
         eFromTo fromToCopilot;
         double coursePilot;
         double courseCopilot;
         double bearing;
         double latDeviationPilot;
         double latDeviationCopilot;
         double range;
         double latDevRateEstPilot;
         double latDevRateEstCopilot;
      } mTacan;

      struct sFlightPlan
      {
         bool isValid;
         double course;
         eFromTo fromTo;
         double bearing;
         double latDeviation;
         double vertDeviation;
         double range;
         double crossTrackDistance;
         double crossTrackAngle;
         int timeToTurn;
      } mFlightPlan;

      struct sAdf
      {
         bool isValid;
         double bearing;
         double range;
      } mAdf;

      double mMagVar;

      struct sAnnunciators
      {
         bool ilsDecisionHeight;
         bool ilsMiddleMarker;
         bool ilsInnerMarker;
         bool ilsOuterMarker;
         bool ilsWithinCone;
         bool displayFlightPlanSeqFlash;
         bool displayFlightPlanVertFlash;
      } mAnnunciators;   };

   sNavigationData *mData;

private:

   HANDLE mMapFile;
};

#endif // __C_NAVIGATION_MANAGER_H__
