void axisAngleTest(GU_Detail *gdp, UT_Vector3D *axis, float angle) {
    ntv::nvec3<float> axisNTV(axis->x(),axis->y(),axis->z());
    ntv::nquat<float> qNTV;

    //std::cout << "fromNTV: " << fromNTV << std::endl;
    //std::cout << "toNTV: " << toNTV << std::endl;
    qNTV.fromAxisAngle(axisNTV, angle);
    std::cout << "qNTV: " << qNTV << std::endl;
    std::cout << "axisn: " << axisNTV.normalized() <<" angle: "<< angle<< std::endl;
    ntv::nvec3<float> gotAxis;
    float gotAngle;
    qNTV.toAxisAngle(gotAxis, gotAngle);
    std::cout << "gotAxis: " << gotAxis << " gotAngle: "<< gotAngle<< std::endl;

}

