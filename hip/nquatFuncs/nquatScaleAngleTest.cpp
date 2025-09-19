void scaleAngleTest(UT_Vector3D *axisA, float angleA, float tau) {
    ntv::nvec3<float> axisNTV_A(axisA->x(),axisA->y(),axisA->z());
    ntv::nquat<float> qNTV_A;

    qNTV_A.fromAxisAngle(axisNTV_A, angleA);
    std::cout << qNTV_A <<" A "<< std::endl;
    ntv::nquat<float> result = qNTV_A.scaleAngle(tau);
    std::cout << result << " scaled\n" <<std::endl;
    std::cout << "axisn:   " << axisNTV_A.normalized() <<" angle:    "<< angleA<< std::endl;
    ntv::nvec3<float> gotAxis;
    float gotAngle;
    qNTV_A.toAxisAngle(gotAxis, gotAngle);
    std::cout << "gotAxis: " << gotAxis << " gotAngle: "<< gotAngle<< std::endl;

}

