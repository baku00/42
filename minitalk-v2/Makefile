CLIENT_NAME = client
SERVER_NAME = server
NAMES = $(CLIENT_NAME) $(SERVER_NAME)
PID = 2951874

INCLUDES = ./includes

FT_PRINTF = $(INCLUDES)/ft_printf
LIB_FT_PRINTF_A = $(FT_PRINTF)/libftprintf.a

OBJS = $(CFILES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(CLIENT_NAME) $(SERVER_NAME)

clean:
	make clean -C $(FT_PRINTF)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(FT_PRINTF)
	rm -rf $(NAMES)

$(CLIENT_NAME): $(OBJS) $(LIB_FT_PRINTF_A)
	$(CC) $(CFLAGS) $(CLIENT_NAME).c $(OBJS) $(LIB_FT_PRINTF_A) -o $(CLIENT_NAME)

$(SERVER_NAME): $(LIB_FT_PRINTF_A)
	$(CC) $(CFLAGS) $(SERVER_NAME).c $(LIB_FT_PRINTF_A) -o $(SERVER_NAME)

$(LIB_FT_PRINTF_A):
	@$(MAKE) -C $(FT_PRINTF)

test:
	./client $(PID) 'Hello my name is Jack'
	./client $(PID) 'I want write a question mark but I don"t know if I can, so I let"s try but excuse me if it doesn"t work'
	./client $(PID) 'How are you doing ?'
	./client $(PID) 'Ooooh yeah it"s work, it"s very nice !'
	./client $(PID) 'Puis-je parler français ? (On sait jamais avec les caractères)'
	./client $(PID) 'Oh mais ce programme est beaucoup trop bien ça marche aussi'
	./client $(PID) 'Donc par exemple je pourrais aussi mettre des caractères accentué'
	./client $(PID) 'Ce programme est vraiment génial !'
	./client $(PID) 'Bon sinon à pars ça, le russe, japonais, chinois ou autre ça marche aussi ou pas ?'
	./client $(PID) 'Итак, давайте посмотрим на русский'
	./client $(PID) 'Это действительно слишком много'
	./client $(PID) '日本人はどうでしょうか？'
	./client $(PID) '我々は優秀であり、中国にとって最後のテスト？\
\
(本当によく効くと思うから）。'
	./client $(PID) "Bon et pour un texte de wikipédia ?"
	./client $(PID) 'Histoire\
2006-2012 : de 0 à cinq cents millions dutilisateurs et utilisatrices\
Croquis préliminaire sur papier de Twitter (alors intitulé « stat.us »).\
\
Twitter a été créé à San Francisco au sein de la start-up Odeo fondée par Noah Glass7 et Evan Williams. Noah Glass commercialisait AudBlog, une application permettant de publier des fichiers audio sur un blog au moyen d’un téléphone. Evan Williams est connu pour être entre autres le cofondateur de la société Pyra Labs, à l’origine de la plateforme de blogs Blogger, achetée par Google en 2003. Odeo proposait une plateforme d"hébergement web, de diffusion et d’enregistrement de podcasts.\
\
Le marché du podcast étant déjà très concurrentiel, Jack Dorsey, ingénieur spécialiste du dispatching, et Noah Glass, ancien collaborateur de Marc Canter (fondateur de MacroMind (en)) et fondateur du service de blog podcasting AudBlog (qui a fusionné avec Odeo), furent chargés de développer un nouveau service[source insuffisante]. L’idée de départ lancée par Jack Dorsey était de permettre aux utilisateurs de partager facilement leurs petits moments de vie avec leurs amis[source insuffisante]. Ouverte au public le 13 juillet 2006, la première version s’intitulait Stat.us puis Twttr, en référence au site de partage de photos Flickr puis Twitter, son nom actuel. Le 21 mars 2006, Jack Dorsey envoyait son premier tweet : « Just setting up my twttr » (« Suis en train d"installer mon twttr »), marquant la date anniversaire de la fondation de l"entreprise par Jack Dorsey, Evan Williams, Biz Stone et Noah Glass8.\
\
Le 25 octobre 2006, les actifs de la société Odeo ont été achetés par Obvious Corp. Puis en avril 2007, une entité indépendante est créée avec comme nom Twitter avec Jack Dorsey à sa tête jusqu’en octobre 2008 date à laquelle Evan Williams lui succéda. En mars 2008, Twitter compte un million d’utilisateurs. La société compte 29 employés en février 20099, 300 en octobre 2010 et 900 en avril 201210.\
\
En juillet 2008, Twitter rachète le moteur de recherche de tweets Summize qui est intégré et devient le moteur de recherche natif de Twitter11. En avril 2010, l"application et client Twitter, Tweetie est achetée, il devient Twitter pour iPhone, Twitter pour Mac12. Si la version Twitter pour iPhone subsiste, Twitter pour Mac est définitivement arrêté en octobre 201213.\
\
Le 4 octobre 2010, Evan Williams, le cofondateur, annonce qu"il passe la main à Dick Costolo, ancien directeur d"exploitation.\
\
Le 25 mai 2011, le client Twitter TweetDeck est acheté pour 40 millions de dollars14. Le 5 juillet 2011 l"outil de gestion analytique de Twitter BackType (en) est acheté15. Le 21 septembre 2011, Twitter acquiert un spécialiste de la recherche sur Internet Julpan, fondé en 2010 par Ori Allon, un ancien employé qui avait travaillé sur le moteur de recherche de Google16.\
\
Le 20 janvier 2012, Twitter acquiert l"agrégateur d"informations torontois Summify17. Le 3 mars 2012, Twitter acquiert le site spécialisé dans les microblogs Posterous, un concurrent de Tumblr18. En avril 2012, Hotspots.io, un service spécialisé dans l"analyse sociale est acheté aussi19. Le 10 mai 2012, Twitter achète le développeur de services marketing personnalisés de notification par e-mail RestEngine20. En octobre 2012, c"est au tour de Vine, un outil new-yorkais qui permet aux utilisateurs de publier des vidéos par tweets via smartphones qui se voit acquis par Twitter21. Cet outil est directement proposé aux utilisateurs de Twitter sur smartphones à partir du 24 janvier 201321.'

re: fclean all

.PHONY: all clean fclean re test
