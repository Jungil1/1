#include <imgproc.hpp>
    
      //Function2 : Detect feature points and refine the detections
  
  // Detect feature points
  void ImgProc::detectFeature()
  {

  for (auto const &f : fileNames) {
    std::cout << std::string(f) << std::endl;

    // 2. Read in the image an call cv::findChessboardCorners()
    img = cv::imread(fileNames[i]);
    

    cv::cvtColor(img, gray, cv::COLOR_RGB2GRAY);

    patternFound = cv::findChessboardCorners(gray, patternSize, q[i], cv::CALIB_CB_ADAPTIVE_THRESH + cv::CALIB_CB_NORMALIZE_IMAGE + cv::CALIB_CB_FAST_CHECK);

    // 2. Use cv::cornerSubPix() to refine the found corner detections
    if(patternFound){
        cv::cornerSubPix(gray, q[i],cv::Size(11,11), cv::Size(-1,-1), cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, 30, 0.1));
        Q.push_back(objp);
    }

    
    cv::drawChessboardCorners(img, patternSize, q[i], patternFound);
    cv::imshow("chessboard detection", img);
    cv::waitKey(0);

    i++;
  }

  }