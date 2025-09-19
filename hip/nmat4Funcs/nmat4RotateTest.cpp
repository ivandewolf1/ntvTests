void rotateTest(GU_Detail *gdp, UT_Vector3D *axis, float angle) {

    UT_Matrix4F m4HDK;
    m4HDK.identity();
    m4HDK.rotate(*axis, angle);

    ntv::nvec3<float> axisNTV(axis->x(),axis->y(),axis->z());
    ntv::nmat4<float> m4NTV;
    m4NTV.rotate(axisNTV, angle);

    std::cout << "\nROTATE\n m4HDK: \n" << m4HDK << std::endl;
    std::cout << "m4NTV: " << m4NTV << std::endl;
    GA_Offset originPtOff = gdp->appendPointOffset();
    GA_Offset newPtOff = gdp->appendPointOffset();
    GU_PrimPoly *newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    gdp->setPos3(newPtOff, UT_Vector3(m4HDK[0]));newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);
    newPtOff = gdp->appendPointOffset();newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    gdp->setPos3(newPtOff, UT_Vector3(m4HDK[1]));newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);
    newPtOff = gdp->appendPointOffset();newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    gdp->setPos3(newPtOff, UT_Vector3(m4HDK[2]));newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);

    ntv::nmat3<float> m3NTV = m4NTV.asM3();
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

