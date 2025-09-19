void fromToTest(GU_Detail *gdp, UT_Vector3D *origin, UT_Vector3D *lookat) {
    ntv::nvec3<float> fromNTV(origin->x(),origin->y(),origin->z());
    ntv::nvec3<float> toNTV(lookat->x(),lookat->y(),lookat->z());
    ntv::nquat<float> qNTV;

    //std::cout << "fromNTV: " << fromNTV << std::endl;
    //std::cout << "toNTV: " << toNTV << std::endl;
    qNTV.RotateFromTo(fromNTV, toNTV);
    std::cout << "qNTV: " << qNTV << std::endl;
}

