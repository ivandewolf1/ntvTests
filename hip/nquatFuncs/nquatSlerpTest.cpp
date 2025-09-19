void slerpTest(UT_Vector3D *axisA, float angleA,UT_Vector3D *axisB, float angleB, float tau) {
    ntv::nvec3<float> axisNTV_A(axisA->x(),axisA->y(),axisA->z());
    ntv::nvec3<float> axisNTV_B(axisB->x(),axisB->y(),axisB->z());
    ntv::nquat<float> qNTV_A;
    ntv::nquat<float> qNTV_B;
    ntv::nquat<float> output;

    qNTV_A.fromAxisAngle(axisNTV_A, angleA);
    std::cout << qNTV_A <<" A "<< std::endl;
    qNTV_B.fromAxisAngle(axisNTV_B, angleB);
    std::cout << qNTV_B << " B "<< std::endl;
    output = qNTV_A.slerp(qNTV_B, tau);
    std::cout << output << "slerp\n" <<std::endl;
}

