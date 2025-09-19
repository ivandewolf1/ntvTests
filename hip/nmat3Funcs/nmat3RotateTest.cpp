void rotateTest(GU_Detail *gdp, UT_Vector3D *axis, float angle) {

    UT_Matrix3F m3HDK;
    m3HDK.identity();
    m3HDK.rotate(*axis, angle);

    ntv::nvec3<float> axisNTV(axis->x(),axis->y(),axis->z());
    ntv::nmat3<float> m3NTV;
    m3NTV.rotate(axisNTV, angle);

    std::cout << "\nROTATE\n m3HDK: \n" << m3HDK << std::endl;
    std::cout << "m3NTV: " << m3NTV << std::endl;
    GA_Offset originPtOff = gdp->appendPointOffset();
    GA_Offset newPtOff = gdp->appendPointOffset();
    GU_PrimPoly *newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    gdp->setPos3(newPtOff, m3HDK[0]);newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);
    newPtOff = gdp->appendPointOffset();newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    gdp->setPos3(newPtOff, m3HDK[1]);newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);
    newPtOff = gdp->appendPointOffset();newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    gdp->setPos3(newPtOff, m3HDK[2]);newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);

    newPtOff = gdp->appendPointOffset();newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    ntv::nvec3<float> gnomon = m3NTV.getRow(0);UT_Vector3D gnomonV(gnomon[0],gnomon[1],gnomon[2]);
    gdp->setPos3(newPtOff, gnomonV);newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);
    newPtOff = gdp->appendPointOffset();newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    gnomon = m3NTV.getRow(1); gnomonV.assign(gnomon[0],gnomon[1],gnomon[2]);
    gdp->setPos3(newPtOff, gnomonV);newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);
    newPtOff = gdp->appendPointOffset();newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    gnomon = m3NTV.getRow(2); gnomonV.assign(gnomon[0],gnomon[1],gnomon[2]);
    gdp->setPos3(newPtOff, gnomonV);newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);
}

