#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

  class Juego{

    private:
        char _nombre[40];
        sf::Font font;
        sf::Music music;
        std::chrono::high_resolution_clock::time_point tiempodeInicio = std::chrono::high_resolution_clock::now();


    public:
        Juego(const char *n="Armored Tanks"){
            strcpy(_nombre,n);
            font.loadFromFile("Fuente/fuente.ttf");
            music.openFromFile("Musica/musicaJuego.ogg");
        }

        void setMusica(int &vol);
        sf::Font& getFuente(){return font;}

        void draw1J(sf::RenderWindow& window, Tanque &tanque, Enemigo &e1, Enemigo &e2, Enemigo &e3, Enemigo &e4);
        void draw2J(sf::RenderWindow& window, Tanque &jugador1, Tanque &jugador2);
        void drawTextos(sf::RenderWindow& window, sf::Text *vTexto, int cant);

        void colisiones1J(Mapa &mapita, Tanque &tanque, Enemigo &enemigo, Enemigo &enemigo2,Enemigo &enemigo3,Enemigo &enemigo4);
        void colisiones2J(Mapa &mapita, Tanque &jugador1,Tanque &jugador2);
        const char *getNombre(){return _nombre;}
        bool cronometro();

        double obtenerTiempoTranscurrido() const {
        auto tiempoActual = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> tiempoTranscurrido = tiempoActual - tiempodeInicio;
        return tiempoTranscurrido.count();
         }

        void juegoTerminado(jugador &jug1, sf::RenderWindow &window, int puntaje){
             Puntaje punt;
             ArchivoPuntajes arcP;

             if(cronometro()|| jug1.getVida()==0){
                punt.setPuntos(puntaje);
                punt.setNombre(jug1.getNombre());
                mejoresTres(punt);
                arcP.guardarPuntaje(punt);
                window.close();

             }

             }

        void juegoTerminado(jugador &jug1, jugador &jug2, sf::RenderWindow &window, int puntajeJ1, int puntajeJ2 ){
                 Puntaje p,p2;

                 ArchivoPuntajes arcP;

             if(cronometro() || jug1.getVida()==0 || jug2.getVida()==0){

                    p.setPuntos(puntajeJ1);
                    p.setNombre(jug1.getNombre());
                    p2.setPuntos(puntajeJ2);
                    p2.setNombre(jug2.getNombre());

                    mejoresTres(p);
                    mejoresTres(p2);

                    arcP.guardarPuntaje(p2);
                    arcP.guardarPuntaje(p);


                    window.close();

             }

             }



        ~Juego(){};

};

void Juego::draw1J(sf::RenderWindow& window, Tanque &tanque, Enemigo &e1, Enemigo &e2, Enemigo &e3, Enemigo &e4){

    window.draw(tanque);
    window.draw(e1);
    window.draw(e2);
    window.draw(e3);
    window.draw(e4);

}

void Juego::draw2J(sf::RenderWindow& window,Tanque &jugador1, Tanque &jugador2){

    window.draw(jugador1);
    window.draw(jugador2);

}

void Juego::drawTextos(sf::RenderWindow& window, sf::Text *vTexto, int cant){

    for(int i=0;i<cant;i++){
        window.draw(vTexto[i]);
    }

}

void Juego::colisiones1J(Mapa &mapita, Tanque &tanque, Enemigo &enemigo, Enemigo &enemigo2,Enemigo &enemigo3,Enemigo &enemigo4){

    ColisionBalas_Bloques(mapita.getBloqueL(),mapita.getBloqueH(),tanque);
    ColisionBalas_Bloques(mapita.getBloqueL(),mapita.getBloqueH(),enemigo);
    ColisionBalas_Bloques(mapita.getBloqueL(),mapita.getBloqueH(),enemigo2);
    ColisionBalas_Bloques(mapita.getBloqueL(),mapita.getBloqueH(),enemigo3);
    ColisionBalas_Bloques(mapita.getBloqueL(),mapita.getBloqueH(),enemigo4);

    ColisionBloques(tanque,mapita.getBloqueL(),mapita.getBloqueH());

}
void Juego::colisiones2J(Mapa &mapita, Tanque &jugador1, Tanque &jugador2){

    ColisionBalas_Bloques(mapita.getBloqueL(),mapita.getBloqueH(),jugador1);
    ColisionBalas_Bloques(mapita.getBloqueL(),mapita.getBloqueH(),jugador2);

    ColisionBloques(jugador1,mapita.getBloqueL(),mapita.getBloqueH());
    ColisionBloques(jugador2,mapita.getBloqueL(),mapita.getBloqueH());

}

void Juego::setMusica(int &vol){

    music.setLoop(true);
    music.setVolume(100.f);

    if(vol==0){
        music.play();
        vol=2;
    }
    else{music.pause();}

}

void setPropTextos(sf::Font &fuente, sf::Text *vTexto, const char *n1){

    vTexto[0].setFont(fuente);
    vTexto[0].setString("ENEMIGO 1");
    vTexto[0].setPosition(730,40);
    vTexto[0].setScale(0.2,0.2);

    vTexto[1].setFont(fuente);
    vTexto[1].setString(n1);
    vTexto[1].setPosition(730,160);
    vTexto[1].setScale(0.3,0.3);

    vTexto[2].setFont(fuente);
    vTexto[2].setString("ENEMIGO 2");
    vTexto[2].setPosition(730,280);
    vTexto[2].setScale(0.2,0.2);

    vTexto[3].setFont(fuente);
    vTexto[3].setString("ENEMIGO 3");
    vTexto[3].setPosition(730,400);
    vTexto[3].setScale(0.2,0.2);

}

void setPropTextos(sf::Font &fuente, sf::Text *vTexto, const char *n1, const char *n2){

    vTexto[0].setFont(fuente);
    vTexto[0].setString(n1);
    vTexto[0].setPosition(730,40); ///VALORES PROPIEDADES TEXTO
    vTexto[0].setScale(0.3,0.3);

    vTexto[1].setFont(fuente);
    vTexto[1].setString(n2);
    vTexto[1].setPosition(730,280);
    vTexto[1].setScale(0.3,0.3);

}

bool Juego::cronometro(){

    auto tiempoActual = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempoTranscurrido = tiempoActual - tiempodeInicio;

    if(tiempoTranscurrido>std::chrono::minutes(5)){
            return true;
    }else{
         return false;
    }

}


int mainModo1Jug(sf::RenderWindow& window, const char *n, int &vol){ ///RECIBE DEL MENU EL BOOL PARA PONER O NO LA MUSICA

    Juego juego;
    jugador jug1(0,0);

    window.setFramerateLimit(60);

    Objeto obj1("Sprites/rayoo.png",true,40,50);
    Objeto obj2("Sprites/corazon.png",true,487,107);
    Objeto obj3("Sprites/fantasma.png",true,336,228);
    Objeto obj4("Sprites/poscion.png",true,216,376);
    Objeto obj5("Sprites/rayoo.png",true,660,450);
    Bloque bloq[200];
    Mapa mapita;


    jug1.setNombre(n);
    sf::Text text[4];
    setPropTextos(juego.getFuente(),text,jug1.getNombre()); ///CARGA TODAS LAS PROPIEDADES DE C/UNO

    juego.setMusica(vol);


    Tanque mansotanque(630,30);
    Enemigo enemigo(33,365,{2,2},100);
    Enemigo enemigo2(33,400,{2,2},100);
    Enemigo enemigo3(80,432,{2,2},100);
    Enemigo enemigo4(115,432,{2,2},100);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                    window.close();
                    return vol;
            }

            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    window.close();
                    return vol;
                }
            }
        }

    window.clear();

    jug1.UpdateDibujarSprite();

    jug1.Disparar(event,window);

    juego.colisiones1J(mapita,jug1,enemigo,enemigo2,enemigo3,enemigo4);
    ///REUNE COLISION BALAS-BLOQUES Y COLISION BLOQUES


    ///COLISIONES BALA DE JUG A ENEMIGOS
    bool colBT1=colisionBalaTanque( jug1,enemigo);
    bool colBT2=colisionBalaTanque( jug1,enemigo2);
    bool colBT3=colisionBalaTanque( jug1,enemigo3);
    bool colBT4=colisionBalaTanque( jug1,enemigo4);
    ///COLISIONES DE ENEMIGO A JUG
    bool colBT5=colisionBalaTanque(enemigo, jug1);
    bool colBT6=colisionBalaTanque(enemigo2, jug1);
    bool colBT7=colisionBalaTanque(enemigo3, jug1);
    bool colBT8=colisionBalaTanque(enemigo4, jug1);

      if(colBT1||colBT2||colBT3||colBT4 ==true){
            jug1.setPuntaje(10);


         }


  bool col=ColisionBloquesEnemigo(enemigo,mapita.getBloqueL(),mapita.getBloqueH());
  bool col2=ColisionBloquesEnemigo(enemigo2,mapita.getBloqueL(),mapita.getBloqueH());
  bool col3=ColisionBloquesEnemigo(enemigo3,mapita.getBloqueL(),mapita.getBloqueH());
  bool col4=ColisionBloquesEnemigo(enemigo4,mapita.getBloqueL(),mapita.getBloqueH());

    enemigo.dispararSolo(event,window);
    enemigo2.dispararSolo(event,window);
    enemigo3.dispararSolo(event,window);
    enemigo4.dispararSolo(event,window);
    enemigo.moverSolo(col);
    enemigo2.moverSolo(col2);
    enemigo3.moverSolo(col3);
    enemigo4.moverSolo(col4);

    ///danio de enemigos a jug
    jug1.danio(colBT5,630,30);
    jug1.danio(colBT6,630,30);
    jug1.danio(colBT7,630,30);
    jug1.danio(colBT8,630,30);
    ///danio de jug a enemigos
    enemigo.danio(colBT1,33,365);
    enemigo2.danio(colBT2,33,400);
    enemigo3.danio(colBT3,80,432);
    enemigo4.danio(colBT4,115,432);


  jug1.dibujarCorazones(event,window,700,50);


    ///PODER DE FLASHHH-FLASHVERSO-FLASHPOINT-FLASHGIL
    bool colobj2=ColisionTanqueObjeto(jug1,obj2);
    bool colobj3=ColisionTanqueObjeto(jug1,obj3);
    bool colobj1=ColisionTanqueObjeto(jug1,obj1);
    bool colobj4=ColisionTanqueObjeto(jug1,obj4);
    bool colobj5=ColisionTanqueObjeto(jug1,obj5);

    obj1.UpdateRapidez(jug1,colobj1,mapita,40,50);
    obj2.upgradeVida(jug1,colobj2,mapita, jug1.getCorazones(),487,107);
    obj3.UpdateFantasma(jug1,colobj3,336,228);
    obj4.UpdateTam(jug1,colobj4,216,270);
    obj5.UpdateRapidez(jug1,colobj5,mapita,660,450);


    obj2.draw(window);
    obj1.draw(window);
    obj3.draw(window);
    obj4.draw(window);
    obj5.draw(window);

    juego.draw1J(window, jug1,enemigo,enemigo2,enemigo3,enemigo4); ///REUNE TODOs LOS DRAW
    juego.drawTextos(window,text,4);
    mapita.dibujarMapa(event,window);
    juego.juegoTerminado(jug1,window,jug1.getPuntaje());
    window.display();

    }

    return 0;

}


int mainModo2jug(sf::RenderWindow& window, const char* t1, const char* t2, int &vol){

    Juego juego;
    jugador jug2(3,0);
    jugador jug1(0,1);

    window.setFramerateLimit(60);

    Objeto obj1("Sprites/rayoo.png",true,40,50);
    Objeto obj2("Sprites/corazon.png",true,487,107);
    Objeto obj3("Sprites/fantasma.png",true,336,228);
    Objeto obj4("Sprites/poscion.png",true,216,376);
    Objeto obj5("Sprites/rayoo.png",true,660,450);

    Bloque bloq[200];
    Mapa mapita;

    jug1.setNombre(t1);
    jug2.setNombre(t2);

    sf::Text text[2];
    setPropTextos(juego.getFuente(),text,jug1.getNombre(),jug2.getNombre());

    juego.setMusica(vol);

    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                window.close();
                return vol;
            }

            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    window.close();
                    return vol;
                }
            }
        }

        window.clear();

    jug1.UpdateDibujarSprite();
    jug1.Disparar(event,window);

    jug2.UpdateDibujarSpriteJug2();
    jug2.DispararJug2(event,window);

    bool colbal1 =colisionBalaTanque(jug1,jug2);
    bool colbal2 = colisionBalaTanque(jug2,jug1);

        if(colbal1){
         jug1.setPuntaje(10);

      }else if(colbal2){
        jug2.setPuntaje(10);

      }



    jug2.danio(colbal1,50,50);
    jug1.danio(colbal2,50,50);

    juego.colisiones2J(mapita,jug1,jug2);

    bool colobj2=ColisionTanqueObjeto(jug1,obj2);
    bool colobj3=ColisionTanqueObjeto(jug1,obj3);
    bool colobj1=ColisionTanqueObjeto(jug1,obj1);
    bool colobj4=ColisionTanqueObjeto(jug1,obj4);
    bool colobj5=ColisionTanqueObjeto(jug1,obj5);

    bool colobj2jug2=ColisionTanqueObjeto(jug2,obj2);
    bool colobj3jug2=ColisionTanqueObjeto(jug2,obj3);
    bool colobj1jug2=ColisionTanqueObjeto(jug2,obj1);
    bool colobj4jug2=ColisionTanqueObjeto(jug2,obj4);
    bool colobj5jug2=ColisionTanqueObjeto(jug2,obj5);

    obj1.UpdateRapidez(jug1,colobj1,mapita,40,50);
    obj2.upgradeVida(jug1,colobj2,mapita, jug1.getCorazones(),487,107);
    obj3.UpdateFantasma(jug1,colobj3,336,228);
    obj4.UpdateTam(jug1,colobj4,216,300);
    obj5.UpdateRapidez(jug1,colobj5,mapita,660,450);

    obj1.UpdateRapidez(jug2,colobj1jug2,mapita,40,50);
    obj2.upgradeVida(jug2,colobj2jug2,mapita, jug2.getCorazones(),487,107);
    obj3.UpdateFantasma(jug2,colobj3jug2,336,228);
    obj4.UpdateTam(jug2,colobj4jug2,216,300);
    obj5.UpdateRapidez(jug2,colobj5jug2,mapita,660,450);

    obj2.draw(window);
    obj1.draw(window);
    obj3.draw(window);
    obj4.draw(window);
    obj5.draw(window);

    juego.draw2J(window,jug1,jug2);
    juego.drawTextos(window,text,2);

    jug1.dibujarCorazones(event,window,700,50);
    jug2.dibujarCorazones(event,window,700,290);

    mapita.dibujarMapa(event,window);
     juego.juegoTerminado(jug1,jug2,window,jug1.getPuntaje(),jug2.getPuntaje());


    window.display();

    }

    return 0;

}


#endif // JUEGO_H_INCLUDED
