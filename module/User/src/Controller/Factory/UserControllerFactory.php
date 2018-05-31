<?php
namespace User\Controller\Factory;

use Interop\Container\ContainerInterface;
use Zend\ServiceManager\Factory\FactoryInterface;
use User\Controller\UserController;
use User\Service\AuthManager;
use User\Service\UserManager;

/**
 * This is the factory for UserController. Its purpose is to instantiate the
 * controller and inject dependencies into it.
 */
class UserControllerFactory implements FactoryInterface
{
    public function __invoke(ContainerInterface $container, $requestedName, array $options = null)
    {
        $entityManager = $container->get('doctrine.entitymanager.orm_default');
        $userManager = $container->get(UserManager::class);
        $authService = $container->get(\Zend\Authentication\AuthenticationService::class);
        $viewHelperManager = $container->get('ViewHelperManager');
        $renderer = $container->get('Zend\View\Renderer\RendererInterface');
        $basePath = $renderer->basePath();

        // Instantiate the controller and inject dependencies
        return new UserController($entityManager, $userManager, $authService, $basePath);
    }
}