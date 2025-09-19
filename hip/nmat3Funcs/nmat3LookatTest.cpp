void lookatTest(GU_Detail *gdp, UT_Vector3D *origin, UT_Vector3D *lookat) {

    UT_Matrix3F m3HDK;
    UT_Vector3D upHDK(0.0,1.0,0.0);
    m3HDK.lookat(*origin, *lookat, upHDK);

    ntv::nvec3<float> fromNTV(origin->x(),origin->y(),origin->z());
    ntv::nvec3<float> toNTV(lookat->x(),lookat->y(),lookat->z());
    ntv::nvec3<float> upNTV(0,1,0);
    ntv::nmat3<float> m3NTV;
    m3NTV.lookat(toNTV-fromNTV, upNTV);

    std::cout << "\nm3HDK: \n" << m3HDK << std::endl;
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
    ntv::nvec3<float> axis = m3NTV.getRow(0);UT_Vector3D axisV(axis[0],axis[1],axis[2]);
    gdp->setPos3(newPtOff, axisV);newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);
    newPtOff = gdp->appendPointOffset();newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    axis = m3NTV.getRow(1); axisV.assign(axis[0],axis[1],axis[2]);
    gdp->setPos3(newPtOff, axisV);newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);
    newPtOff = gdp->appendPointOffset();newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    axis = m3NTV.getRow(2); axisV.assign(axis[0],axis[1],axis[2]);
    gdp->setPos3(newPtOff, axisV);newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);

    /*newPtOff = gdp->appendPointOffset();newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    axis = m3NTV.getColumn(1); axisV(axis[0],axis[1],axis[2]);
    gdp->setPos3(newPtOff, axis);newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);
    newPtOff = gdp->appendPointOffset();newPoly = GU_PrimPoly::build(gdp, 0, GU_POLY_OPEN, 0);
    axis = m3NTV.getColumn(2); axisV(axis[0],axis[1],axis[2]);
    gdp->setPos3(newPtOff, axis);newPoly->appendVertex(originPtOff);newPoly->appendVertex(newPtOff);*/

    //ntv::nvec3<float> fromV(origin->x(),origin->y(),origin->z());
    //ntv::nvec3<float> toV(lookat->x(),lookat->y(),lookat->z());

    /*ntv::nmat4<float> m4;
    m4.lookat(fromV, toV);
    ntv::nmat4<float> m4I = m4.transpose().inverse().transpose();
    std::cout<<"YO!"<<m4<< "---"<<m4I<<std::endl;
    UT_Matrix4 foo;*/
    /*ntv::nvec3<float> zeeV(0,0,1);
    ntv::nquat<float> qLook;
    qLook.RotateFromTo(zeeV, toV);
    ntv::nquat<float> q(.1,.2,.3,.4);
    q.normalize();
    q = q.slerp(qLook,tau);*/
    /*GA_Offset ptoff;
    GA_FOR_ALL_PTOFF(gdp, ptoff)
    {
        UT_Vector3 pos = gdp->getPos3(ptoff);
        ntv::nvec3<float> posV(pos.x(),pos.y(),pos.z());
        posV = m4*posV;
        posV = m4I*posV;
        //pos.y() += 1.0;
        pos.assign(posV[0],posV[1],posV[2]);
        gdp->setPos3(ptoff, pos);
    }*/
    //return 1234;
}

