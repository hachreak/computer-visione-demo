CC = g++
CFLAGS = -O3 -Wall 

SRCDIR   = ./src/
BINDIR   = ./bin

FLAGS=-DBINARIZATION

all: bin/01_pgm_copy bin/02_pgm_istogramma bin/03_pgm_soglia_binarizzazione bin/04_pgm_abbassamento_luminosita bin/05_filtro_mediano bin/07_differenza_immagini bin/08_ritaglio_immagine bin/06_estrazione_contorni bin/09_pgm_labelizzazione

$(BINDIR)/%:  $(SRCDIR)%.cpp 
	$(CC) $(CFLAGS) $(FLAGS) -o $@ $<

clean: 
	rm -f bin/*

