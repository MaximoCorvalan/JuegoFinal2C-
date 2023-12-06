#ifndef COLISIONES_H_INCLUDED
#define COLISIONES_H_INCLUDED

///AGREGUE LA COLISION CON LOS BLOQUES DE HIERRO, POR ESA RAZON
///NO COLISIONABA NUESTRO TANQUE CON ALGUNOS BLOQUES
///SI VES UN ERROR,  AL INTENTAR PASAR POR ABAJO A LA IZQUIERDA, DEBE SER POR MALA UBICACION DE LOS BLOQUES
///PERO ESPERAMOS QUE ASTRID HAGA EL MAPITA
void ColisionBloques(Tanque &mansotanque,Bloque *bloq, Bloque *bloqH){
    int i=0;
    int x=0,y=0;
    while(i<141){
            x=mansotanque.getx();
            y=mansotanque.gety();
            if(mansotanque.isCollision(bloq[i]) && bloq[i].getEstado()==true && mansotanque.getEstado()==true)
            {
                if(mansotanque.getOrientacion()==4)
                {
                    cout << "Colisión detectada. Antes: (" << mansotanque.getx() << ", " << mansotanque.gety() << ")" << endl;
                    mansotanque.setx(mansotanque.getx()-5);
                    mansotanque.sety(y);
                    cout<<"4";
                    cout << "Colisión detectada. Ahora: (" << mansotanque.getx() << ", " << mansotanque.gety() << ")" << endl;
                }
                else if(mansotanque.getOrientacion()==3)
                {
                    cout << "Colisión detectada. Antes: (" << mansotanque.getx() << ", " << mansotanque.gety() << ")" << endl;
                    mansotanque.setx(mansotanque.getx()+5);
                    mansotanque.sety(y);
                    cout<<"3";
                    cout << "Colisión detectada. Ahora: (" << mansotanque.getx() << ", " << mansotanque.gety() << ")" << endl;
                }
                else if(mansotanque.getOrientacion()==2)
                {
                    cout << "Colisión detectada. Antes: (" << mansotanque.getx() << ", " << mansotanque.gety() << ")" << endl;
                    mansotanque.sety(mansotanque.gety()-5);
                    mansotanque.setx(x);
                    cout<<"2";
                    cout << "Colisión detectada. Ahora: (" << mansotanque.getx() << ", " << mansotanque.gety() << ")" << endl;
                }
                else if(mansotanque.getOrientacion()==1)
                {
                    cout << "Colisión detectada. Antes: (" << mansotanque.getx() << ", " << mansotanque.gety() << ")" << endl;
                    mansotanque.sety(mansotanque.gety()+5);
                    mansotanque.setx(x);
                    cout<<"1";
                    cout << "Colisión detectada. Ahora: (" << mansotanque.getx() << ", " << mansotanque.gety() << ")" << endl;
                }

            }
            i++;
    }
    i=0;
    while(i<10){
            x=mansotanque.getx();
            y=mansotanque.gety();
            if(mansotanque.isCollision(bloqH[i]) && mansotanque.getEstado()==true)
            {
                if(mansotanque.getOrientacion()==4)
                {

                    mansotanque.setx(mansotanque.getx()-5);
                    mansotanque.sety(y);

                }
                else if(mansotanque.getOrientacion()==3)
                {

                    mansotanque.setx(mansotanque.getx()+5);
                    mansotanque.sety(y);
                }
                else if(mansotanque.getOrientacion()==2)
                {

                    mansotanque.sety(mansotanque.gety()-5);
                    mansotanque.setx(x);

                }
                else if(mansotanque.getOrientacion()==1)
                {

                    mansotanque.sety(mansotanque.gety()+5);
                    mansotanque.setx(x);

                }

            }
            i++;
    }
}




bool ColisionBloquesEnemigo(Enemigo &enemigo,Bloque *bloq, Bloque *bloqH){
    int i=0;
    bool colision =false;
    int x=0,y=0;
    while(i<200){
            x=enemigo.getx();
            y=enemigo.gety();
            if(enemigo.isCollision(bloq[i])&&bloq[i].getEstado())
            {

                if(enemigo.getOrientacion()==4)
                {
                    enemigo.setx(enemigo.getx()-5);
                    enemigo.sety(y);

                }
                else if(enemigo.getOrientacion()==3)
                {
                    enemigo.setx(enemigo.getx()+5);
                    enemigo.sety(y);
           ;
                }
                else if(enemigo.getOrientacion()==2)
                {
                    enemigo.sety(enemigo.gety()-5);
                    enemigo.setx(x);

                }
                else if(enemigo.getOrientacion()==1)
                {
                    enemigo.sety(enemigo.gety()+5);
                    enemigo.setx(x);

                }
              colision=true;
            }
            i++;
    }
    i=0;
    while(i<10){
            x=enemigo.getx();
            y=enemigo.gety();
            if(enemigo.isCollision(bloqH[i]))
            {
                if(enemigo.getOrientacion()==4)
                {
                    enemigo.setx(enemigo.getx()-5);
                    enemigo.sety(y);

                }
                else if(enemigo.getOrientacion()==3)
                {
                    enemigo.setx(enemigo.getx()+5);
                    enemigo.sety(y);

                }
                else if(enemigo.getOrientacion()==2)
                {
                    enemigo.sety(enemigo.gety()-5);
                    enemigo.setx(x);

                }
                else if(enemigo.getOrientacion()==1)
                {
                    enemigo.sety(enemigo.gety()+5);
                    enemigo.setx(x);

                }
                    colision=true;
            }
            i++;
    }
    return colision;
}


void ColisionBalas_Bloques(Bloque *bloqL,Bloque *bloqH,Tanque &mansotanque){
    int i=0;


   auto it=mansotanque.getBala().begin();

   while(it !=mansotanque.getBala().end()){

         bool balaDeleted = false;
        while(i<200){

            if(bloqL[i].isCollision(**it) && bloqL[i].getEstado()&&i>80 && bloqL[i].getTipo()==1){
                  delete *it;
                 it = mansotanque.getBala().erase(it);
                  bloqL[i].setDurabilidad(bloqL[i].getDurabilidad()-50);
                  bloqL[i].ladrilloRoto();
                  if(bloqL[i].getDurabilidad()==0){
                    bloqL[i].setEstado(false);
                  }
                  balaDeleted=true;
                  break;

            }


              if(bloqH[i].isCollision(**it) && bloqH[i].getTipo()==2){
                delete *it;
                 it = mansotanque.getBala().erase(it);
                  balaDeleted=true;
                  break;
            }
             i++;
        }
         if(!balaDeleted){
            it++;
            }
   }
}

bool colisionBalaTanque(Tanque &tan1,Tanque &tanq2){
    bool delatedBala;
    auto it=tan1.getBala().begin();





     while(it!=tan1.getBala().end()){
       delatedBala=false;

        if(tanq2.isCollision(**it)&& tanq2.getEstado()==true){
            delete *it;
              it = tan1.getBala().erase(it);
              delatedBala=true;

              return true;


        }

        if(!delatedBala){

                 it++;
        }

     }


}


bool ColisionTanqueObjeto(Tanque &tanq, Objeto &obj){
if(tanq.isCollision(obj)&&obj.getEstado()==true){
    return true;
}else{
    return false;
}
}



#endif // COLISIONES_H_INCLUDED
